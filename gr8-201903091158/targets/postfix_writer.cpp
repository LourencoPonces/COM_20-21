#include <string>
#include <sstream>
#include <memory>
#include "targets/postfix_writer.h"
#include "targets/type_checker.h"
#include "targets/frame_size_calculator.h"
#include "targets/symbol.h"
#include "ast/all.h"
// must come after other #includes
#include "gr8_parser.tab.h"

void gr8::postfix_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}

void gr8::postfix_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}

void gr8::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}

void gr8::postfix_writer::do_block_node(gr8::block_node * const node, int lvl) {
  _symtab.push(); // for block-local vars
  if (node->declarations()) node->declarations()->accept(this, lvl + 2);
  if (node->instructions()) node->instructions()->accept(this, lvl + 2);
  _symtab.pop();
}

void gr8::postfix_writer::do_return_node(gr8::return_node * const node, int lvl) {
  ASSERT_SAFE;

  // should not reach here without returning a value (if not void)
  if (_function->type()->name() != basic_type::TYPE_VOID) {
    node->retval()->accept(this, lvl + 2);

    if (_function->type()->name() == basic_type::TYPE_INT || _function->type()->name() == basic_type::TYPE_STRING
        || _function->type()->name() == basic_type::TYPE_POINTER) {
      _pf.STFVAL32();
    } else if (_function->type()->name() == basic_type::TYPE_DOUBLE) {
      if (node->retval()->type()->name() == basic_type::TYPE_INT)
        _pf.I2D();
      _pf.STFVAL64();
    } else {
      std::cerr << node->lineno() << ": should not happen: unknown return type" << std::endl;
    }
  }
  _pf.LEAVE();
  _pf.RET();
}

void gr8::postfix_writer::do_variable_declaration_node(gr8::variable_declaration_node * const node, int lvl) {
  ASSERT_SAFE;

  auto id = node->identifier();
  // type size?
  int offset = 0, typesize = node->varType()->size();// in bytes
  std::cout << "ARG: " << id << ", " << typesize << std::endl;
  if (_inFunctionBody) {
    _offset -= typesize;
    offset = _offset;
  } else if (_inFunctionArgs) {
    offset = _offset;
    _offset += typesize;
  } else {
    offset = 0; // global variable
  }

  std::shared_ptr<gr8::symbol> symbol = new_symbol();
  if (symbol) {
    symbol->set_offset(offset);
    reset_new_symbol();
  }

  if (_inFunctionBody) {
    // if we are dealing with local variables, then no action is needed
    // unless an initializer exists
    if (node->initializer()) {
      node->initializer()->accept(this, lvl);
      if (node->varType()->name() == basic_type::TYPE_INT || node->varType()->name() == basic_type::TYPE_STRING
          || node->varType()->name() == basic_type::TYPE_POINTER) {
        _pf.LOCAL(symbol->offset());
        _pf.STINT();
      } else if (node->varType()->name() == basic_type::TYPE_DOUBLE) {
        _pf.LOCAL(symbol->offset());
        _pf.STDOUBLE();
      } else {
        std::cerr << "cannot initialize" << std::endl;
      }
    }
  } else {
    if (!_function) {
      if (node->initializer() == nullptr) {
        _pf.BSS();
        _pf.ALIGN();
        _pf.LABEL(id);
        _pf.SALLOC(typesize);
      } else {

        if (node->varType()->name() == basic_type::TYPE_INT || node->varType()->name() == basic_type::TYPE_DOUBLE
            || node->varType()->name() == basic_type::TYPE_POINTER) {

          if (node->constant()) {
            _pf.RODATA();
          }
          else {
            _pf.DATA();
          }
          _pf.ALIGN();
          _pf.LABEL(id);

          if (node->varType()->name() == basic_type::TYPE_INT) {
            node->initializer()->accept(this, lvl);
          } else if (node->varType()->name() == basic_type::TYPE_POINTER) {
            node->initializer()->accept(this, lvl);
          } else if (node->varType()->name() == basic_type::TYPE_DOUBLE) {
            if (node->initializer()->type()->name() == basic_type::TYPE_DOUBLE) {
              node->initializer()->accept(this, lvl);
            } else if (node->initializer()->type()->name() == basic_type::TYPE_INT) {
              cdk::integer_node *dclini = dynamic_cast<cdk::integer_node *>(node->initializer());
              cdk::double_node ddi(dclini->lineno(), dclini->value());
              ddi.accept(this, lvl);
            } else {
              std::cerr << node->lineno() << ": '" << id << "' has bad initializer for real value\n";
              _errors = true;
            }
          }
        } else if (node->varType()->name() == basic_type::TYPE_STRING) {
          if (node->constant()) {
            int litlbl;
            // HACK!!! string literal initializers must be emitted before the string identifier
            _pf.RODATA();
            _pf.ALIGN();
            _pf.LABEL(mklbl(litlbl = ++_lbl));
            _pf.SSTRING(dynamic_cast<cdk::string_node *>(node->initializer())->value());
            _pf.ALIGN();
            _pf.LABEL(id);
            _pf.SADDR(mklbl(litlbl));
          } else {
            _pf.DATA();
            _pf.ALIGN();
            _pf.LABEL(id);
            node->initializer()->accept(this, lvl);
          }
        } else {
          std::cerr << node->lineno() << ": '" << id << "' has unexpected initializer\n";
          _errors = true;
        }

      }

    }
  }

}

//===========================================================================

void gr8::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
  if (_inFunctionBody) {
    _pf.DOUBLE(node->value()); // load number to the stack
  } else {
    _pf.SDOUBLE(node->value());    // double is on the DATA segment
  }
}

void gr8::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  if (_inFunctionBody) {
    _pf.INT(node->value()); // integer literal is on the stack: push an integer
  } else {
    _pf.SINT(node->value()); // integer literal is on the DATA segment
  }
}

void gr8::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;
  /* generate the string literal */
  _pf.RODATA(); // strings are readonly DATA
  _pf.ALIGN(); // make sure the address is aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.SSTRING(node->value()); // output string characters
  if (_function) {
    // local variable initializer
    _pf.TEXT();
    _pf.ADDR(mklbl(lbl1));
  } else {
    // global variable initializer
    _pf.DATA();
    _pf.SADDR(mklbl(lbl1));
  }
}

//===========================================================================

void gr8::postfix_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  ASSERT_SAFE;

  const std::string &id = node->name();
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);
  if (symbol->global()) {
    _pf.ADDR(symbol->name());
  }
  else {
    _pf.LOCAL(symbol->offset());
  }
}

void gr8::postfix_writer::do_left_index_node(gr8::left_index_node * const node, int lvl) {
  ASSERT_SAFE;
  if (node->base()) {
    node->base()->accept(this, lvl);
  } else {
    if (_function) {
      _pf.LOCV(-_function->type()->size());
    } else {
      std::cerr << "FATAL: " << node->lineno() << ": trying to use return value outside function" << std::endl;
    }
  }
  node->index()->accept(this, lvl);
  _pf.INT(3);
  _pf.SHTL();
  _pf.ADD(); // add pointer and index
}

void gr8::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE;
  node->lvalue()->accept(this, lvl);
  if (node->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.LDDOUBLE();
  }
  else {
    // integers, pointers, and strings
    _pf.LDINT();
  }
}

void gr8::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE;

  node->rvalue()->accept(this, lvl + 2);
  if (node->type()->name() == basic_type::TYPE_DOUBLE) {
    if (node->rvalue()->type()->name() == basic_type::TYPE_INT)
    _pf.I2D();
    _pf.DUP64();
  } else {
    _pf.DUP32();
  }

  node->lvalue()->accept(this, lvl);
  if (node->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.STDOUBLE();
  } else {
    _pf.STINT();
  }
}

//===========================================================================

void gr8::postfix_writer::do_read_node(gr8::read_node * const node, int lvl) {
  //DAVID: FIXME: should ASSERT_SAFE?
  if (_lvalueType == basic_type::TYPE_DOUBLE) {
    _functions_to_declare.insert("readd");
    _pf.CALL("readd");
    _pf.LDFVAL64();
  } else if (_lvalueType == basic_type::TYPE_INT) {
    _functions_to_declare.insert("readi");
    _pf.CALL("readi");
    _pf.LDFVAL32();
  } else {
    std::cerr << "FATAL: " << node->lineno() << ": cannot read type" << std::endl;
    return;
  }
}

void gr8::postfix_writer::do_print_node(gr8::print_node * const node, int lvl) {
  ASSERT_SAFE;
  basic_type *etype = node->argument()->type();
  node->argument()->accept(this, lvl); // expression to print
  if (etype->name() == basic_type::TYPE_INT) {
    _functions_to_declare.insert("printi");
    _pf.CALL("printi");
    _pf.TRASH(4); // trash int
  } else if (etype->name() == basic_type::TYPE_DOUBLE) {
    _functions_to_declare.insert("printd");
    _pf.CALL("printd");
    _pf.TRASH(8); // trash double
  } else if (etype->name() == basic_type::TYPE_STRING) {
    _functions_to_declare.insert("prints");
    _pf.CALL("prints");
    _pf.TRASH(4); // trash char pointer
  } else {
    std::cerr << "cannot print expression of unknown type" << std::endl;
    return;
  }

  if (node->newline()) {
    _functions_to_declare.insert("println");
    _pf.CALL("println");
  }
}

void gr8::postfix_writer::do_evaluation_node(gr8::evaluation_node * const node, int lvl) {
  ASSERT_SAFE;
  basic_type *type = node->expression()->type();
  node->expression()->accept(this, lvl);
  _pf.TRASH(type->size());
}

//===========================================================================

void gr8::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_SAFE;
  node->argument()->accept(this, lvl); // process node data
  _pf.NEG();
}

void gr8::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {
  ASSERT_SAFE;
  node->argument()->accept(this, lvl + 2);
  _pf.INT(0);
  _pf.EQ();
  //_pf.NOT();
}

//===========================================================================

void gr8::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE;

  node->left()->accept(this, lvl + 2);
  if (node->type()->name() == basic_type::TYPE_DOUBLE && node->left()->type()->name() == basic_type::TYPE_INT) {
    _pf.I2D();
  } else if (node->type()->name() == basic_type::TYPE_POINTER && node->left()->type()->name() == basic_type::TYPE_INT) {
    _pf.INT(3);
    _pf.SHTL();
  }

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == basic_type::TYPE_DOUBLE && node->right()->type()->name() == basic_type::TYPE_INT) {
    _pf.I2D();
  } else if (node->type()->name() == basic_type::TYPE_POINTER && node->right()->type()->name() == basic_type::TYPE_INT) {
    _pf.INT(3);
    _pf.SHTL();
  }

  if (node->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.DADD();
  else
  _pf.ADD();
}

void gr8::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE;

  node->left()->accept(this, lvl + 2);
  if (node->type()->name() == basic_type::TYPE_DOUBLE && node->left()->type()->name() == basic_type::TYPE_INT)
  _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == basic_type::TYPE_DOUBLE && node->right()->type()->name() == basic_type::TYPE_INT) {
    _pf.I2D();
  } else if (node->type()->name() == basic_type::TYPE_POINTER && node->right()->type()->name() == basic_type::TYPE_INT) {
    _pf.INT(3);
    _pf.SHTL();
  }

  if (node->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.DSUB();
  else
  _pf.SUB();
}

void gr8::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE;

  node->left()->accept(this, lvl + 2);
  if (node->type()->name() == basic_type::TYPE_DOUBLE && node->left()->type()->name() == basic_type::TYPE_INT)
  _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == basic_type::TYPE_DOUBLE && node->right()->type()->name() == basic_type::TYPE_INT)
  _pf.I2D();

  if (node->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.DMUL();
  else
  _pf.MUL();
}

void gr8::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE;

  node->left()->accept(this, lvl + 2);
  if (node->type()->name() == basic_type::TYPE_DOUBLE && node->left()->type()->name() == basic_type::TYPE_INT)
  _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == basic_type::TYPE_DOUBLE && node->right()->type()->name() == basic_type::TYPE_INT)
  _pf.I2D();

  if (node->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.DDIV();
  else
  _pf.DIV();
}

void gr8::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  _pf.MOD();
}

//===========================================================================

void gr8::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  _pf.GE();
}

void gr8::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  _pf.GT();
}

void gr8::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  _pf.LE();
}

void gr8::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  _pf.LT();
}

//===========================================================================

void gr8::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
  ASSERT_SAFE;
  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JZ(mklbl(lbl));
  node->right()->accept(this, lvl + 2);
  _pf.AND();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

void gr8::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
  ASSERT_SAFE;
  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JNZ(mklbl(lbl));
  node->right()->accept(this, lvl + 2);
  _pf.OR();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

//===========================================================================

void gr8::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  _pf.EQ();
}

void gr8::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
  _pf.I2D();

  _pf.NE();
}

//===========================================================================

void gr8::postfix_writer::do_address_of_node(gr8::address_of_node * const node, int lvl) {
  ASSERT_SAFE;
  // since the argument is an lvalue, it is already an address
  node->lvalue()->accept(this, lvl + 2);
}

void gr8::postfix_writer::do_stack_alloc_node(gr8::stack_alloc_node * const node, int lvl) {
  ASSERT_SAFE;
  node->argument()->accept(this, lvl);
  _pf.INT(3);
  _pf.SHTL();
  _pf.ALLOC(); // allocate
  _pf.SP();// put base pointer in stack
}

void gr8::postfix_writer::do_nullptr_node(gr8::nullptr_node * const node, int lvl) {
  ASSERT_SAFE; // a pointer is a 32-bit integer
  if (_inFunctionBody) {
    _pf.INT(0);
  } else {
    _pf.SINT(0);
  }
}

//===========================================================================

void gr8::postfix_writer::do_sweep_node(gr8::sweep_node * const node, int lvl) {
  ASSERT_SAFE;

  _forIni.push(++_lbl); // after init, before body
  _forStep.push(++_lbl);// after intruction
  _forEnd.push(++_lbl);// after for

  int stepelsejmp = ++_lbl;
  int stepjmp = ++_lbl;

  os() << "        ;; FOR initialize" << std::endl;
  // initialize: be careful with variable declarations:
  // they are done here, but the space is occupied in the function
  _inForInit = true;// remember this for local declarations

  // initialize
  node->begin()->accept(this, lvl + 2);
  node->lvalue()->accept(this, lvl + 2);
  _pf.STINT();

  os() << "        ;; FOR test" << std::endl;
  // prepare to test
  _pf.ALIGN();
  _pf.LABEL(mklbl(_forIni.top()));
  node->lvalue()->accept(this, lvl + 2);
  _pf.LDINT();
  node->end()->accept(this, lvl + 2);

  //DAVID: horrible hack: evaluates step multiple times (possibly ok)
  node->step()->accept(this, lvl + 2);
  _pf.INT(0);
  _pf.LT();
  _pf.JZ(mklbl(stepelsejmp));
  _pf.GE();
  _pf.JMP(mklbl(stepjmp));
  _pf.LABEL(mklbl(stepelsejmp));
  _pf.LE();// default (go up)
  _pf.LABEL(mklbl(stepjmp));
  _pf.JZ(mklbl(_forEnd.top()));

  os() << "        ;; FOR instruction" << std::endl;
  // execute instruction
  node->instruction()->accept(this, lvl + 2);

  os() << "        ;; FOR increment" << std::endl;
  // prepare to increment
  _pf.ALIGN();
  _pf.LABEL(mklbl(_forStep.top()));
  node->lvalue()->accept(this, lvl + 2);
  _pf.LDINT();
  node->step()->accept(this, lvl + 2);
  _pf.ADD();
  node->lvalue()->accept(this, lvl + 2);
  _pf.STINT();

  os() << "        ;; FOR jump to test" << std::endl;
  _pf.JMP(mklbl(_forIni.top()));

  os() << "        ;; FOR end" << std::endl;
  _pf.ALIGN();
  _pf.LABEL(mklbl(_forEnd.top()));

  _inForInit = false;// remember this for local declarations

  _forIni.pop();
  _forStep.pop();
  _forEnd.pop();
}

void gr8::postfix_writer::do_next_node(gr8::next_node * const node, int lvl) {
  if (_forIni.size() != 0) {
    _pf.JMP(mklbl(_forStep.top())); // jump to next cycle
  } else
    error(node->lineno(), "'restart' outside 'for'");
}

void gr8::postfix_writer::do_stop_node(gr8::stop_node * const node, int lvl) {
  if (_forIni.size() != 0) {
    _pf.JMP(mklbl(_forEnd.top())); // jump to for end
  } else
    error(node->lineno(), "'break' outside 'for'");
}

//===========================================================================

void gr8::postfix_writer::do_if_node(gr8::if_node * const node, int lvl) {
  ASSERT_SAFE;
  int lbl_end;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl_end = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl_end));
}

void gr8::postfix_writer::do_if_else_node(gr8::if_else_node * const node, int lvl) {
  ASSERT_SAFE;
  int lbl_else, lbl_end;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl_else = lbl_end = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  if (node->elseblock()) {
    _pf.JMP(mklbl(lbl_end = ++_lbl));
    _pf.LABEL(mklbl(lbl_else));
    node->elseblock()->accept(this, lvl + 2);
  }
  _pf.LABEL(mklbl(lbl_end));
}

//===========================================================================

void gr8::postfix_writer::do_function_call_node(gr8::function_call_node * const node, int lvl) {
  ASSERT_SAFE;

  size_t argsSize = 0;
  if (node->arguments()) {
    for (int ax = node->arguments()->size(); ax > 0; ax--) {
      cdk::expression_node *arg = dynamic_cast<cdk::expression_node*>(node->arguments()->node(ax - 1));
      arg->accept(this, lvl + 2);
      argsSize += arg->type()->size();
    }
  }
  _pf.CALL(node->identifier());
  if (argsSize != 0) {
    _pf.TRASH(argsSize);
  }

  std::shared_ptr<gr8::symbol> symbol = _symtab.find(node->identifier());

  basic_type *type = symbol->type();
  if (type->name() == basic_type::TYPE_INT || type->name() == basic_type::TYPE_POINTER || type->name() == basic_type::TYPE_STRING) {
    _pf.LDFVAL32();
  }
  else if (type->name() == basic_type::TYPE_DOUBLE) {
    _pf.LDFVAL64();
  }
  else {
    // cannot happer!
  }
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_function_declaration_node(gr8::function_declaration_node * const node, int lvl) {
  if (_inFunctionBody || _inFunctionArgs) {
    error(node->lineno(), "cannot declare function in body or in args");
    return;
  }

  //DAVID: FIXME: should be at the beginning
  ASSERT_SAFE;

  if (!new_symbol()) return;

  std::shared_ptr<gr8::symbol> function = new_symbol();
  _functions_to_declare.insert(function->name());
  reset_new_symbol();
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_function_definition_node(gr8::function_definition_node * const node, int lvl) {
  if (_inFunctionBody || _inFunctionArgs) {
    error(node->lineno(), "cannot define function in body or in arguments");
    return;
  }

  //DAVID: FIXME: should be at the beginning
  ASSERT_SAFE;

  // remember symbol so that args and body know
  _function = new_symbol();
  _functions_to_declare.erase(_function->name());  // just in case
  reset_new_symbol();

  _offset = 8; // prepare for arguments (4: remember to account for return address)
  _symtab.push(); // scope of args
  if (node->arguments()) {
    _inFunctionArgs = true; //FIXME really needed?
    for (size_t ix = 0; ix < node->arguments()->size(); ix++) {
      cdk::basic_node *arg = node->arguments()->node(ix);
      if (arg == nullptr) break; // this means an empty sequence of arguments
      arg->accept(this, 0); // the function symbol is at the top of the stack
    }
    _inFunctionArgs = false; //FIXME really needed?
  }

  _pf.TEXT();
  _pf.ALIGN();
  if (node->qualifier() == tPUBLIC) _pf.GLOBAL(_function->name(), _pf.FUNC());
  _pf.LABEL(_function->name());

  // compute stack size to be reserved for local variables
  frame_size_calculator lsc(_compiler, _symtab);
  node->accept(&lsc, lvl);
  _pf.ENTER(lsc.localsize()); // total stack size reserved for local variables

  // the following flag is a slight hack: it won't work with nested functions
  _inFunctionBody = true;
  // prepare for local variables but remember the return value (first below fp)
  _offset = -_function->type()->size();
  os() << "        ;; before body " << std::endl;
  node->block()->accept(this, lvl + 4); // block has its own scope
  os() << "        ;; after body " << std::endl;
  _inFunctionBody = false;
  _symtab.pop(); // scope of arguments

  //DAVID: nasty hack!
  _pf.LEAVE();
  _pf.RET();

  if (node->identifier() == "covfefe") {
    // declare external functions
    for (std::string s : _functions_to_declare)
      _pf.EXTERN(s);
  }
}

//---------------------------------------------------------------------------
//-----------------------     T H E    E N D     ----------------------------
//---------------------------------------------------------------------------
