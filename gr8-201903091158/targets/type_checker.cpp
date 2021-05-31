#include <string>
#include <memory>
#include "targets/type_checker.h"
#include "targets/symbol.h"
#include "ast/all.h"
// must come after other #includes
#include "gr8_parser.tab.h"

#define ASSERT_UNSPEC { if (node->type() != nullptr && node->type()->name() != basic_type::TYPE_UNSPEC) return; }

//---------------------------------------------------------------------------

void gr8::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}
void gr8::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void gr8::type_checker::do_block_node(gr8::block_node *const node, int lvl) {
  // EMPTY
}
void gr8::type_checker::do_next_node(gr8::next_node *const node, int lvl) {
  // EMPTY
}
void gr8::type_checker::do_stop_node(gr8::stop_node *const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

gr8::type_checker::~type_checker() {
  os().flush();
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_return_node(gr8::return_node *const node, int lvl) {
  if (node->retval()) {
    if (_function->type()->name() == basic_type::TYPE_VOID) throw std::string("initializer specified for void function.");

    node->retval()->accept(this, lvl + 2);

    std::cout << "FUNCT TYPE" << _function->type()->name()  << std::endl;
    std::cout << "RETVAL TYPE" << node->retval()->type()->name() << std::endl;

    if (_function->type()->name() == basic_type::TYPE_INT) {
      if (node->retval()->type()->name() != basic_type::TYPE_INT) throw std::string(
          "wrong type for initializer (integer expected).");
    } else if (_function->type()->name() == basic_type::TYPE_DOUBLE) {
      if (node->retval()->type()->name() != basic_type::TYPE_INT
          && node->retval()->type()->name() != basic_type::TYPE_DOUBLE) throw std::string(
          "wrong type for initializer (integer or double expected).");
    } else if (_function->type()->name() == basic_type::TYPE_STRING) {
      if (node->retval()->type()->name() != basic_type::TYPE_STRING) throw std::string(
          "wrong type for initializer (string expected).");
    } else if (_function->type()->name() == basic_type::TYPE_POINTER) {
      //DAVID: FIXME: trouble!!!
      int ft = 0, rt = 0;
      basic_type *ftype = _function->type();
      for (; ftype->name() == basic_type::TYPE_POINTER; ft++, ftype = ftype->_subtype);
      basic_type *rtype = node->retval()->type();
      for (; rtype && rtype->name() == basic_type::TYPE_POINTER; rt++, rtype = rtype->_subtype);
      
    std::cout << "FUNCT TYPE"  << _function->type()->name()      << " --- " << ft << " -- " << ftype->name() << std::endl;
    std::cout << "RETVAL TYPE" << node->retval()->type()->name() << " --- " << rt << " -- " << rtype << std::endl;

      bool compatible = (ft == rt) && (rtype == 0 || (rtype != 0 && ftype->name() == rtype->name()));
      if (!compatible) throw std::string("wrong type for return expression (pointer expected).");

    } else {
      throw std::string("unknown type for initializer.");
    }
  }
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_double_node(cdk::double_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
}

void gr8::type_checker::do_integer_node(cdk::integer_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void gr8::type_checker::do_string_node(cdk::string_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_STRING));
}

void gr8::type_checker::do_nullptr_node(gr8::nullptr_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_POINTER));
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);
  if (symbol) {
    node->type(symbol->type());
  } else {
    throw std::string("undeclared variable '" + id + "'");
  }
}

void gr8::type_checker::do_left_index_node(gr8::left_index_node * const node, int lvl) {
  ASSERT_UNSPEC;
  if (node->base()) {
    node->base()->accept(this, lvl + 2);
    if (node->base()->type()->name() != basic_type::TYPE_POINTER) throw std::string(
        "pointer expression expected in index left-value");
  } else {
    if (_function->type()->name() != basic_type::TYPE_POINTER) throw std::string(
        "return pointer expression expected in index left-value");
  }
  node->index()->accept(this, lvl + 2);
  if (node->index()->type()->name() != basic_type::TYPE_INT) throw std::string("integer expression expected in left-value index");
  node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
}

void gr8::type_checker::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl);
  node->type(node->lvalue()->type());
}

void gr8::type_checker::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 4);
  node->rvalue()->accept(this, lvl + 4);

  if (node->lvalue()->type()->name() == basic_type::TYPE_INT) {
    if (node->rvalue()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(4, basic_type::TYPE_INT));
    } else if (node->rvalue()->type()->name() == basic_type::TYPE_UNSPEC) {
      node->type(new basic_type(4, basic_type::TYPE_INT));
      node->rvalue()->type(new basic_type(4, basic_type::TYPE_INT));
    } else
      throw std::string("wrong assignment to integer");
  } else if (node->lvalue()->type()->name() == basic_type::TYPE_POINTER) {

//TODO: check pointer level

    if (node->rvalue()->type()->name() == basic_type::TYPE_POINTER) {
      node->type(new basic_type(4, basic_type::TYPE_POINTER));
    } else if (node->rvalue()->type()->name() == basic_type::TYPE_INT) {
      //TODO: check that the integer is a literal and that it is zero
      node->type(new basic_type(4, basic_type::TYPE_POINTER));
    } else if (node->rvalue()->type()->name() == basic_type::TYPE_UNSPEC) {
      node->type(new basic_type(4, basic_type::TYPE_ERROR));
      node->rvalue()->type(new basic_type(4, basic_type::TYPE_ERROR));
    } else
      throw std::string("wrong assignment to pointer");

  } else if (node->lvalue()->type()->name() == basic_type::TYPE_DOUBLE) {

    if (node->rvalue()->type()->name() == basic_type::TYPE_DOUBLE || node->rvalue()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
    } else if (node->rvalue()->type()->name() == basic_type::TYPE_UNSPEC) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
      node->rvalue()->type(new basic_type(8, basic_type::TYPE_DOUBLE));
    } else
      throw std::string("wrong assignment to real");

  } else if (node->lvalue()->type()->name() == basic_type::TYPE_STRING) {

    if (node->rvalue()->type()->name() == basic_type::TYPE_STRING) {
      node->type(new basic_type(4, basic_type::TYPE_STRING));
    } else if (node->rvalue()->type()->name() == basic_type::TYPE_UNSPEC) {
      node->type(new basic_type(4, basic_type::TYPE_STRING));
      node->rvalue()->type(new basic_type(4, basic_type::TYPE_STRING));
    } else
      throw std::string("wrong assignment to string");

  } else {
    throw std::string("wrong types in assignment");
  }

}

//---------------------------------------------------------------------------

void gr8::type_checker::do_variable_declaration_node(gr8::variable_declaration_node * const node, int lvl) {
  if (node->initializer() != nullptr) {
    node->initializer()->accept(this, lvl + 2);

    if (node->varType()->name() == basic_type::TYPE_INT) {
      if (node->initializer()->type()->name() != basic_type::TYPE_INT) throw std::string(
          "wrong type for initializer (integer expected).");
    } else if (node->varType()->name() == basic_type::TYPE_DOUBLE) {
      if (node->initializer()->type()->name() != basic_type::TYPE_INT
          && node->initializer()->type()->name() != basic_type::TYPE_DOUBLE) throw std::string(
          "wrong type for initializer (integer or double expected).");
    } else if (node->varType()->name() == basic_type::TYPE_STRING) {
      if (node->initializer()->type()->name() != basic_type::TYPE_STRING) throw std::string(
          "wrong type for initializer (string expected).");
    } else if (node->varType()->name() == basic_type::TYPE_POINTER) {
      //DAVID: FIXME: trouble!!!
      if (node->initializer()->type()->name() != basic_type::TYPE_POINTER) throw std::string(
          "wrong type for initializer (pointer expected).");
    } else {
      throw std::string("unknown type for initializer.");
    }
  }

  const std::string &id = node->identifier();
  std::shared_ptr<gr8::symbol> symbol = std::make_shared < gr8::symbol > (node->constant(), // is it a constant?
  node->qualifier(), // qualifiers: public, forward, "private" (i.e., none)
  node->varType(), // type (type id + type size)
  id, // identifier
  (bool)node->initializer(), // initialized?
  false); // is it a function?
  if (_symtab.insert(id, symbol)) {
    _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
  } else {
    throw std::string("variable '" + id + "' redeclared");
  }
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl);
  if (node->argument()->type()->name() == basic_type::TYPE_INT)
    node->type(node->argument()->type());
  else
    throw std::string("integer or vector expressions expected");
}

//---------------------------------------------------------------------------
//protected:
#if 0
void gr8::type_checker::do_(cdk::expression_node *const node, int lvl, const char *tag) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl+2);
  if (((gr8::Expression*)node->argument())->type() == basic_type::TYPE_INT ||
      ((gr8::Expression*)node->argument())->type() == basic_type::TYPE_NX6)
  node->type(((gr8::Expression*)node->argument())->type());
  else node->type(basic_type::TYPE_UNSPEC);
  node->right()->accept(this, lvl+2);
}
#endif

//---------------------------------------------------------------------------
//protected:
void gr8::type_checker::do_IntOnlyExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() != basic_type::TYPE_INT) throw std::string(
      "integer expression expected in binary operator (left)");

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() != basic_type::TYPE_INT) throw std::string(
      "integer expression expected in binary operator (right)");

  node->type(new basic_type(4, basic_type::TYPE_INT));
}

//---------------------------------------------------------------------------
//protected:
void gr8::type_checker::do_IDExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->type()->name() == basic_type::TYPE_DOUBLE && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  else if (node->left()->type()->name() == basic_type::TYPE_DOUBLE && node->right()->type()->name() == basic_type::TYPE_INT)
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  else if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  else if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_INT)
    node->type(new basic_type(4, basic_type::TYPE_INT));
  else if (node->left()->type()->name() == basic_type::TYPE_UNSPEC && node->right()->type()->name() == basic_type::TYPE_UNSPEC) {
// for @ in @ + @
    node->type(new basic_type(4, basic_type::TYPE_INT));
    node->left()->type(new basic_type(4, basic_type::TYPE_INT));
    node->right()->type(new basic_type(4, basic_type::TYPE_INT));
  } else
    throw std::string("wrong types in binary expression");
}

//---------------------------------------------------------------------------
//protected:
void gr8::type_checker::do_PIDExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->type()->name() == basic_type::TYPE_DOUBLE && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  else if (node->left()->type()->name() == basic_type::TYPE_DOUBLE && node->right()->type()->name() == basic_type::TYPE_INT)
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  else if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_DOUBLE)
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  else if (node->left()->type()->name() == basic_type::TYPE_POINTER && node->right()->type()->name() == basic_type::TYPE_INT)
    node->type(new basic_type(4, basic_type::TYPE_POINTER));
  else if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_POINTER)
    node->type(new basic_type(4, basic_type::TYPE_POINTER));
  else if (node->left()->type()->name() == basic_type::TYPE_INT && node->right()->type()->name() == basic_type::TYPE_INT)
    node->type(new basic_type(4, basic_type::TYPE_INT));
  else if (node->left()->type()->name() == basic_type::TYPE_UNSPEC && node->right()->type()->name() == basic_type::TYPE_UNSPEC) {
// for @ in @ + @
    node->type(new basic_type(4, basic_type::TYPE_INT));
    node->left()->type(new basic_type(4, basic_type::TYPE_INT));
    node->right()->type(new basic_type(4, basic_type::TYPE_INT));
  } else
    throw std::string("wrong types in binary expression");
}

//---------------------------------------------------------------------------
//protected:
void gr8::type_checker::do_ScalarLogicalExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() != basic_type::TYPE_INT) throw std::string(
      "integer expression expected in binary logical expression (left)");

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() != basic_type::TYPE_INT) throw std::string(
      "integer expression expected in binary logical expression (right)");

  node->type(new basic_type(4, basic_type::TYPE_INT));
}

//protected:
void gr8::type_checker::do_BooleanLogicalExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() != basic_type::TYPE_INT) throw std::string("integer expression expected in binary expression");

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() != basic_type::TYPE_INT) throw std::string("integer expression expected in binary expression");

  node->type(new basic_type(4, basic_type::TYPE_INT));
}

//protected:
void gr8::type_checker::do_GeneralLogicalExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  if (node->left()->type()->name() != node->right()->type()->name()) throw std::string(
      "same type expected on both sides of equality operator");
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

//---------------------------------------------------------------------------
//public:
void gr8::type_checker::do_add_node(cdk::add_node * const node, int lvl) {
  do_PIDExpression(node, lvl);
}
void gr8::type_checker::do_sub_node(cdk::sub_node * const node, int lvl) {
  do_PIDExpression(node, lvl);
}
void gr8::type_checker::do_mul_node(cdk::mul_node * const node, int lvl) {
  do_IDExpression(node, lvl);
}
void gr8::type_checker::do_div_node(cdk::div_node * const node, int lvl) {
  do_IDExpression(node, lvl);
}
void gr8::type_checker::do_mod_node(cdk::mod_node * const node, int lvl) {
  do_IntOnlyExpression(node, lvl);
}

//public:
void gr8::type_checker::do_not_node(cdk::not_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->type()->name() == basic_type::TYPE_INT)
    node->type(new basic_type(4, basic_type::TYPE_INT));
  else if (node->argument()->type()->name() == basic_type::TYPE_UNSPEC) {
    node->type(new basic_type(4, basic_type::TYPE_INT));
    node->argument()->type(new basic_type(4, basic_type::TYPE_INT));
  } else
    throw std::string("wrong type in unary logical expression");
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_gt_node(cdk::gt_node * const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void gr8::type_checker::do_ge_node(cdk::ge_node * const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void gr8::type_checker::do_le_node(cdk::le_node * const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void gr8::type_checker::do_lt_node(cdk::lt_node * const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void gr8::type_checker::do_eq_node(cdk::eq_node * const node, int lvl) {
  do_GeneralLogicalExpression(node, lvl);
}
void gr8::type_checker::do_ne_node(cdk::ne_node * const node, int lvl) {
  do_GeneralLogicalExpression(node, lvl);
}

void gr8::type_checker::do_and_node(cdk::and_node * const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}
void gr8::type_checker::do_or_node(cdk::or_node * const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}

//===========================================================================

void gr8::type_checker::do_evaluation_node(gr8::evaluation_node * const node, int lvl) {
  node->expression()->accept(this, lvl + 2);
}
void gr8::type_checker::do_print_node(gr8::print_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->type()->name() == basic_type::TYPE_VOID) {
    throw std::string("wrong type in print argument");
  }
}
void gr8::type_checker::do_read_node(gr8::read_node * const node, int lvl) {
  node->type(new basic_type(0, basic_type::TYPE_UNSPEC));
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_address_of_node(gr8::address_of_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 2);
  if (node->lvalue()->type()->name() == basic_type::TYPE_DOUBLE) {
    node->type(new basic_type(4, basic_type::TYPE_POINTER));
  } else {
    throw std::string("wrong type in unary logical expression");
  }
}

void gr8::type_checker::do_stack_alloc_node(gr8::stack_alloc_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->type()->name() != basic_type::TYPE_INT) throw std::string(
      "integer expression expected in allocation expression");
//FIXME: check the following two lines
  auto mytype = new basic_type(4, basic_type::TYPE_POINTER);
  mytype->_subtype = new basic_type(8, basic_type::TYPE_DOUBLE);
  node->type(mytype);
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_sweep_node(gr8::sweep_node * const node, int lvl) {
  node->lvalue()->accept(this, lvl + 4);
  if (node->lvalue()->type()->name() != basic_type::TYPE_INT) throw std::string("expected integer left-value in for cycle");
  node->begin()->accept(this, lvl + 4);
  if (node->begin()->type()->name() != basic_type::TYPE_INT) throw std::string(
      "expected integer expression as lower bound of for cycle");
  node->end()->accept(this, lvl + 4);
  if (node->end()->type()->name() != basic_type::TYPE_INT) throw std::string(
      "expected integer expression as upper bound of for cycle");
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_if_node(gr8::if_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  if (node->condition()->type()->name() != basic_type::TYPE_INT) throw std::string("expected integer condition");
}

void gr8::type_checker::do_if_else_node(gr8::if_else_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  if (node->condition()->type()->name() != basic_type::TYPE_INT) throw std::string("expected integer condition");
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_function_call_node(gr8::function_call_node * const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->identifier();
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);

  if (symbol == nullptr) throw std::string("symbol '" + id + "' is undeclared.");

  if (!symbol->isFunction()) throw std::string("symbol '" + id + "' is not a function.");

  node->type(symbol->type());

  //DAVID: FIXME: should also validate args against symbol
  if (node->arguments()) {
    node->arguments()->accept(this, lvl + 4);
  }
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_function_declaration_node(gr8::function_declaration_node * const node, int lvl) {
  std::string id;

  // "fix" naming issues...
  if (node->identifier() == "covfefe")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id = node->identifier();

  // remember symbol so that args know
  std::shared_ptr<gr8::symbol> function = std::make_shared < gr8::symbol
      > (false, node->qualifier(), node->type(), id, false, true, true);

  std::shared_ptr<gr8::symbol> previous = _symtab.find(function->name());
  if (previous) {
    if (false /*DAVID: FIXME: should verify fields*/) {
      throw std::string("conflicting declaration for '" + function->name() + "'");
    }
  } else {
    _symtab.insert(function->name(), function);
    _parent->set_new_symbol(function);
  }
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_function_definition_node(gr8::function_definition_node * const node, int lvl) {
  std::string id;

  // "fix" naming issues...
  if (node->identifier() == "covfefe")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id = node->identifier();

  // remember symbol so that args know
  std::shared_ptr<gr8::symbol> function = std::make_shared < gr8::symbol
      > (false, node->qualifier(), node->type(), id, false, true);
  function->set_offset(-node->type()->size());

  std::shared_ptr<gr8::symbol> previous = _symtab.find(function->name());
  if (previous) {
    if (previous->forward()
        && ((previous->qualifier() == tPUBLIC && node->qualifier() == tPUBLIC)
            || (previous->qualifier() == tPRIVATE && node->qualifier() == tPRIVATE))) {
      _symtab.replace(function->name(), function);
      _parent->set_new_symbol(function);
    } else {
      throw std::string("conflicting definition for '" + function->name() + "'");
    }
  } else {
    _symtab.insert(function->name(), function);
    _parent->set_new_symbol(function);
  }
}

//---------------------------------------------------------------------------
//-----------------------     T H E    E N D     ----------------------------
//---------------------------------------------------------------------------
