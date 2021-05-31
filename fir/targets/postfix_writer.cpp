#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "ast/all.h" 
#include "fir_parser.tab.h"
#include "targets/frame_size_calculator.h"




//---------------------------------------------------------------------------
void fir::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void fir::postfix_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  if (_inFunctionBody) {
    _pf.INT(node->value());
  } else {
    _pf.SINT(node->value());
  }
}

void fir::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
  if (_inFunctionBody) {
    _pf.DOUBLE(node->value());
  } else {
    _pf.SDOUBLE(node->value());
  }
}
void fir::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;
  _pf.RODATA(); 
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1 = ++_lbl));
  _pf.SSTRING(node->value()); 

  _pf.ALIGN();
  if (_function) {
    _pf.TEXT(); 
    _pf.ADDR(mklbl(lbl1)); 
  } 
  else {
    _pf.DATA();
    _pf.SADDR(mklbl(lbl1));
  }
}

void fir::postfix_writer::do_null_node(fir::null_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if (_inFunctionBody) {
    _pf.INT(0);
  } else {
    _pf.SINT(0);
  }
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_identity_node(fir::identity_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
}

void fir::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
  if(node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.DNEG();
  }
  else if(node->is_typed(cdk::TYPE_INT)) {
    _pf.NEG();
  }
}

void fir::postfix_writer::do_address_of_node(fir::address_of_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS
  node->lvalue()->accept(this, lvl);
}

void fir::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
  _pf.INT(0);
  _pf.EQ();
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(node->is_typed(cdk::TYPE_DOUBLE) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }

  node->right()->accept(this, lvl);
  if(node->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }

  if(node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.DMUL();
  }
  else {
    _pf.MUL();
  }
}

void fir::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(node->is_typed(cdk::TYPE_DOUBLE) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }

  node->right()->accept(this, lvl);
  if(node->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }

  if(node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.DDIV();
  }
  else {
    _pf.DIV();
  }
}

void fir::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl);
  if (node->is_typed(cdk::TYPE_DOUBLE) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }
  else if (node->is_typed(cdk::TYPE_POINTER) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.INT(3);
    _pf.SHTL();
  }

  node->right()->accept(this, lvl + 2);
  if (node->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }
  else if (node->is_typed(cdk::TYPE_POINTER) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.INT(3); 
    _pf.SHTL();
  }

  if (node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.DADD();
  }
  else {
    _pf.ADD();
  }
}

void fir::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) { 
  ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl + 2);
  if (node->is_typed(cdk::TYPE_DOUBLE) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }
  else if (node->is_typed(cdk::TYPE_POINTER) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.INT(3);
    _pf.SHTL();
  }

  node->right()->accept(this, lvl + 2);
  if (node->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }
  else if (node->is_typed(cdk::TYPE_POINTER) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.INT(3);
    _pf.SHTL();
  }

  if (node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.DSUB();
  }
  else {
    _pf.SUB();
  }
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(node->right()->is_typed(cdk::TYPE_DOUBLE) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }

  node->right()->accept(this, lvl);
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) || node->right()->is_typed(cdk::TYPE_DOUBLE))
  {
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.LT();
}
void fir::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(node->right()->is_typed(cdk::TYPE_DOUBLE) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }

  node->right()->accept(this, lvl);
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) || node->right()->is_typed(cdk::TYPE_DOUBLE))
  {
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.GT();
}
void fir::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(node->right()->is_typed(cdk::TYPE_DOUBLE) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }

  node->right()->accept(this, lvl);
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) || node->right()->is_typed(cdk::TYPE_DOUBLE))
  {
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.LE();
}
void fir::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(node->right()->is_typed(cdk::TYPE_DOUBLE) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }

  node->right()->accept(this, lvl);
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) || node->right()->is_typed(cdk::TYPE_DOUBLE))
  {
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.GE();
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(node->right()->is_typed(cdk::TYPE_DOUBLE) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }

  node->right()->accept(this, lvl);
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) || node->right()->is_typed(cdk::TYPE_DOUBLE))
  {
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.EQ();
}
void fir::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(node->right()->is_typed(cdk::TYPE_DOUBLE) && node->left()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }

  node->right()->accept(this, lvl);
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    _pf.I2D();
  }
  if(node->left()->is_typed(cdk::TYPE_DOUBLE) || node->right()->is_typed(cdk::TYPE_DOUBLE))
  {
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.NE();
}


//---------------------------------------------------------------------------
void fir::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl = ++_lbl;
  node->left()->accept(this, lvl);
  _pf.DUP32();
  _pf.JZ(mklbl(lbl));
  node->right()->accept(this, lvl);
  _pf.AND();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}
void fir::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JNZ(mklbl(lbl));
  node->right()->accept(this, lvl + 2);
  _pf.OR();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  std::shared_ptr<fir::symbol> var = _symtab.find(node->name());
  if(var->offset() == 0){
    _pf.ADDR(node->name()); 
  }
  else{
    _pf.LOCAL(var->offset());
  }
}



void fir::postfix_writer::do_variable_definition_node(fir::variable_definition_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  auto id = node->identifier();
  int offset = 0;
  int typesize = node->type()->size(); 

  if (_inFunctionBody) {
    _offset -= typesize;
    offset = _offset;
  } 
  else if (_inFunctionArgs) {
    offset = _offset;
    _offset += typesize;
  } 
  else {
    offset = 0;
  }

  std::shared_ptr<fir::symbol> symbol = new_symbol();
  if (symbol) {
    symbol->set_offset(offset);
    reset_new_symbol();
  }

  if (node->qualifier() == 2) { //tREQUIRE
    _pf.EXTERN(id);
  }
if(!node->initializer()){
  if (!_inFunctionBody && !_inFunctionArgs && (node->is_typed(cdk::TYPE_INT) || node->is_typed(cdk::TYPE_POINTER)
        || node->is_typed(cdk::TYPE_DOUBLE) || node->is_typed(cdk::TYPE_STRING)) )
      {
        _pf.BSS();
        _pf.ALIGN();
        _pf.LABEL(id);
        _pf.SALLOC(typesize); 
      }
  }

else{
    if (_inFunctionBody) {
      node->initializer()->accept(this, lvl);
      if (node->is_typed(cdk::TYPE_INT) || node->is_typed(cdk::TYPE_STRING)
      || node->is_typed(cdk::TYPE_POINTER)) {
        _pf.LOCAL(offset);
        _pf.STINT();
      } 
      else if (node->is_typed(cdk::TYPE_DOUBLE)) {
        if (node->initializer()->is_typed(cdk::TYPE_INT)) {
          _pf.I2D();
        }
        _pf.LOCAL(offset);
        _pf.STDOUBLE();
      } 
    } 
    else if (!_inFunctionBody && !_inFunctionArgs){
      if (!_function) { 
        if (node->is_typed(cdk::TYPE_INT) || node->is_typed(cdk::TYPE_STRING)
        || node->is_typed(cdk::TYPE_POINTER) || node->is_typed(cdk::TYPE_DOUBLE)) {
          _pf.DATA();
          _pf.ALIGN();
          if (node->qualifier() == 1) { 
            _pf.GLOBAL(id, _pf.OBJ()); 
          }
          _pf.LABEL(id);
        }
        if (node->is_typed(cdk::TYPE_INT) || node->is_typed(cdk::TYPE_STRING)
        || node->is_typed(cdk::TYPE_POINTER)) {
          node->initializer()->accept(this, lvl + 2);
        }
        else if (node->is_typed(cdk::TYPE_DOUBLE)) {
          if (node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
            node->initializer()->accept(this, lvl + 2);
          }
          else if (node->initializer()->is_typed(cdk::TYPE_INT)) {
            cdk::integer_node *i = dynamic_cast<cdk::integer_node *>(node->initializer());
            cdk::double_node d(i->lineno(), i->value());
            d.accept(this, lvl + 2);
          }
          else {
            error(node->lineno(), "'" + id + "' has bad initializer for real value");
          }
        }
        else {
          error(node->lineno(), "'" + id + "' has unexpected initializer");
        }
      }
    }
  }
}



void fir::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  if(node->is_typed(cdk::TYPE_INT) || node->is_typed(cdk::TYPE_POINTER) || 
     node->is_typed(cdk::TYPE_STRING)) 
    _pf.LDINT();
  else if(node->is_typed(cdk::TYPE_DOUBLE))
    _pf.LDDOUBLE();
}

void fir::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->rvalue()->accept(this, lvl); 
  if(node->is_typed(cdk::TYPE_DOUBLE)){
    if(node->rvalue()->is_typed(cdk::TYPE_INT))
      _pf.I2D();
    _pf.DUP64();
  }
  else
    _pf.DUP32();

  node->lvalue()->accept(this, lvl);
  if(node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.STDOUBLE();
  }
  else {
    _pf.STINT();
  }
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_evaluation_node(fir::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl + 2); // determine the value
  if (node->argument()->is_typed(cdk::TYPE_INT) ||
      node->argument()->is_typed(cdk::TYPE_STRING) ||
      node->argument()->is_typed(cdk::TYPE_POINTER)) {
    _pf.TRASH(4);
  } else if (node->argument()->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.TRASH(8);
  } else if (!node->argument()->is_typed(cdk::TYPE_VOID)){      // function_call
    std::cerr << "ERROR: Type is not valid" << std::endl;
    exit(1);
  }
}
void fir::postfix_writer::do_stack_alloc_node(fir::stack_alloc_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl + 2);
  _pf.INT(3); 
  _pf.SHTL();
  _pf.ALLOC(); 
  _pf.SP();
}
void fir::postfix_writer::do_index_node(fir::index_node *const node, int lvl) {
  // EMPTY
  ASSERT_SAFE_EXPRESSIONS;
  if (node->base()) {
    node->base()->accept(this, lvl + 2);
  }
  else {
    if (_function) {
      _pf.LOCV(-_function->type()->size());
    } else {
      std::cerr << "return value can not be used outside the body of the function" << std::endl;
    }
  }
  node->index()->accept(this, lvl + 2);
  _pf.INT(3);
  _pf.SHTL();
  _pf.ADD(); // add pointer and index
}

void fir::postfix_writer::do_sizeof_node(fir::sizeof_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  _pf.INT(0);
  _pf.INT(node->expression()->type()->size());
  _pf.ADD();
}



//---------------------------------------------------------------------------
void fir::postfix_writer::do_while_node(fir::while_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  _symtab.push();

  _whileCondition.push_back(++_lbl);
  _whileEnd.push_back(++_lbl);

  _pf.ALIGN(); 
  _pf.LABEL(mklbl(_whileCondition.back()));
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(_whileEnd.back()));

  node->doblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(_whileCondition.back()));

  _pf.ALIGN();
  _pf.LABEL(mklbl(_whileEnd.back()));

  _whileCondition.pop_back();
  _whileEnd.pop_back();

  _symtab.pop();
}
void fir::postfix_writer::do_while_finally_node(fir::while_finally_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  _symtab.push();

  _whileCondition.push_back(++_lbl);
  _whileEnd.push_back(++_lbl);

  _pf.ALIGN(); 
  _pf.LABEL(mklbl(_whileCondition.back()));
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(_whileEnd.back()));

  node->doblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(_whileCondition.back()));

  _pf.ALIGN();
  _pf.LABEL(mklbl(_whileEnd.back()));

  node->finallyblock()->accept(this, lvl + 2);

  _whileCondition.pop_back();
  _whileEnd.pop_back();

  _symtab.pop();

}

void fir::postfix_writer::do_leave_node(fir::leave_node *const node, int lvl) {
  int cycle = node->nCycle();
  if (_whileCondition.size() != 0) {
    _pf.JMP(mklbl(_whileEnd[_whileEnd.size() - cycle]));
  }
  else
    error(node->lineno(), "'leave' outside 'while'");
}

void fir::postfix_writer::do_restart_node(fir::restart_node *const node, int lvl) {
  int cycle = node->nCycle();
  if (_whileCondition.size() != 0) {
    _pf.JMP(mklbl(_whileCondition[_whileCondition.size() - cycle]));
  } 
  else
    error(node->lineno(), "'restart' outside 'while'");
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_if_node(fir::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1));
}
void fir::postfix_writer::do_if_else_node(fir::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));

  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));

  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);

  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1 = lbl2));
}



//---------------------------------------------------------------------------
void fir::postfix_writer::do_body_node(fir::body_node *const node, int lvl) {
  _symtab.push();
  _currentBodyRetLabel = mklbl(++_lbl);
  if (node->prologue()) 
    node->prologue()->accept(this, lvl + 2);
  if (node->block()) 
    node->block()->accept(this, lvl + 2);
  if (node->epilogue()) 
    node->epilogue()->accept(this, lvl + 2);
  _symtab.pop();
}

void fir::postfix_writer::do_prologue_node(fir::prologue_node *const node, int lvl) {
  _symtab.push(); 
  if (node->block()) 
    node->block()->accept(this, lvl + 2);
  _symtab.pop();
}



void fir::postfix_writer::do_block_node(fir::block_node *const node, int lvl) {
  _symtab.push();
  if (node->declarations()) 
    node->declarations()->accept(this, lvl + 2);
  if (node->instructions()) 
    node->instructions()->accept(this, lvl + 2);
  _symtab.pop();
}


void fir::postfix_writer::do_function_declaration_node(fir::function_declaration_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if (_inFunctionBody || _inFunctionArgs) {
    error(node->lineno(), "cannot declare function in body or in args");
    return;
  }
  if (!new_symbol()) return;

  auto function = new_symbol();
  _functions_to_declare.insert(function->identifier());
  reset_new_symbol();
}




void fir::postfix_writer::do_function_definition_node(fir::function_definition_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if (_inFunctionBody || _inFunctionArgs) {
    error(node->lineno(), "cannot define function in body or in arguments");
    return;
  }
  _function = new_symbol();
  _functions_to_declare.erase(_function->identifier()); 
  reset_new_symbol();


  _offset = 8; 
  _symtab.push();

  if (node->arguments()->size() > 0) {
    _inFunctionArgs = true; 
    for (size_t ix = 0; ix < node->arguments()->size(); ix++) {
      cdk::basic_node *arg = node->arguments()->node(ix);
      if (arg == nullptr) break; 
      arg->accept(this, 0);
    }
    _inFunctionArgs = false;
  }

  _pf.TEXT();
  _pf.ALIGN();
  if (node->qualifier() == 1) { 
    _pf.GLOBAL(_function->identifier(), _pf.FUNC());
  }
  _pf.LABEL(_function->identifier());

  frame_size_calculator lsc(_compiler, _symtab, _function);
  node->accept(&lsc, lvl);
  _pf.ENTER(lsc.localsize()); // total stack size reserved for local variables

  _offset = -_function->type()->size();
  _inFunctionBody = true;

  if (node->default_return_value()){
    node->default_return_value()->accept(this, lvl + 2);
      _pf.LOCAL(_offset);
      _pf.STINT();
  }

  os() << "        ;; before body " << std::endl;
  node->body()->accept(this, lvl + 4);
  os() << "        ;; after body " << std::endl;
  _inFunctionBody = false;
  _returnSeen = false;
  _pf.LABEL(_currentBodyRetLabel);
  _pf.LEAVE();
  _pf.RET();

  _symtab.pop(); 

  if (node->identifier() == "fir") {
    for (std::string s : _functions_to_declare)
      _pf.EXTERN(s);
  }
}



void fir::postfix_writer::do_function_call_node(fir::function_call_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  auto symbol = _symtab.find(node->identifier());
  size_t argsSize = 0;
  if (node->arguments()->size() > 0) {
    for (int ax = node->arguments()->size() - 1; ax >= 0; ax--) {
      cdk::expression_node *arg = dynamic_cast<cdk::expression_node*>(node->arguments()->node(ax));
      arg->accept(this, lvl + 2);
      if (symbol->is_typed(cdk::TYPE_DOUBLE) && arg->is_typed(cdk::TYPE_INT)) {
        _pf.I2D();
      }
      argsSize += symbol->arguments_types().at(ax)->size(); 
    }
  }
  _pf.CALL(node->identifier());
  if (argsSize != 0) {
    _pf.TRASH(argsSize);
  }

  if (symbol->is_typed(cdk::TYPE_INT) || symbol->is_typed(cdk::TYPE_POINTER) || symbol->is_typed(cdk::TYPE_STRING)) {
    _pf.LDFVAL32();
  } 
  else if (symbol->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.LDFVAL64();
  } 
}

void fir::postfix_writer::do_return_node(fir::return_node *const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------
void fir::postfix_writer::do_write_node(fir::write_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  node->arguments()->accept(this, lvl);
  for (size_t i = 0; i < node->arguments()->size(); i++) {
    cdk::expression_node *const expression = dynamic_cast<cdk::expression_node *const>(node->arguments()->node(i));
    expression->accept(this, lvl + 2); // determine the value to print

    if (expression->is_typed(cdk::TYPE_INT)) {
      _functions_to_declare.insert("printi");
      _pf.CALL("printi");
      _pf.TRASH(4); // delete the printed value's address
    } 
    else if (expression->is_typed(cdk::TYPE_DOUBLE)) {
      _functions_to_declare.insert("printd");
      _pf.CALL("printd");
      _pf.TRASH(8); // delete the printed value's address
    } 
    else if (expression->is_typed(cdk::TYPE_STRING)) {
      _functions_to_declare.insert("prints");
      _pf.CALL("prints");
      _pf.TRASH(4); // delete the printed value's address
    } 
    else {
      exit(1);
    }
  }

  if (node->newL()) {
    _functions_to_declare.insert("println");
    _pf.CALL("println");
  }
}

void fir::postfix_writer::do_read_node(fir::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if(node->is_typed(cdk::TYPE_INT))
  {
    _pf.CALL("readi");
    _pf.LDFVAL32();
  }
  else if (node->is_typed(cdk::TYPE_DOUBLE))
  {
    _pf.CALL("readd");
    _pf.LDFVAL64();
  }
}




