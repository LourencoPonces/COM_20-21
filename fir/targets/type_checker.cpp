#include <string>
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated
#include <cdk/types/primitive_type.h>

#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }

//---------------------------------------------------------------------------

void fir::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}

//---------------------------------------------------------------------------
void fir::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}


//---------------------------------------------------------------------------
void fir::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}
void fir::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}
void fir::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
}
void fir::type_checker::do_null_node(fir::null_node *const node, int lvl) {
  ASSERT_UNSPEC
  node->type(cdk::reference_type::create(4, nullptr));
}

//---------------------------------------------------------------------------
void fir::type_checker::processUnaryExpressionInt(cdk::unary_operation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) 
    throw std::string("wrong type in argument of unary expression");

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::processUnaryExpressionIntDouble(cdk::unary_operation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT)) 
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if (node->argument()->is_typed(cdk::TYPE_DOUBLE))
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else 
     throw std::string("wrong type in argument of unary expression");
}

void fir::type_checker::do_identity_node(fir::identity_node *const node, int lvl) {
  processUnaryExpressionIntDouble(node, lvl);
}

void fir::type_checker::do_neg_node(cdk::neg_node *const node, int lvl) {
  processUnaryExpressionIntDouble(node, lvl);
}

void fir::type_checker::do_address_of_node(fir::address_of_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 2);
  node->type(cdk::reference_type::create(4, node->lvalue()->type()));
}

void fir::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl);
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } 
  else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node*>(node->argument());
    if(read != nullptr) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    }
    else
      throw std::string("Unknown node with unspecified type.");
  } 
  else {
    throw std::string("wrong type in unary logical expression");
  }
}

//---------------------------------------------------------------------------
void fir::type_checker::processBinaryExpressionInt(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) 
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else
    throw std::string("wrong type in arguments of binary expression");
}

void fir::type_checker::processBinaryExpressionIntDouble(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) 
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if ((node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE)) ||
           (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) ||
           (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE)))
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));  
  else
    throw std::string("wrong type in arguments of binary expression");
}

void fir::type_checker::processBinaryExpressionIntDoublePointer(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) 
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if ((node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE)) ||
           (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) ||
           (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE)))
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));  
  else if ((node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_POINTER)) ||
           (node->left()->is_typed(cdk::TYPE_POINTER) && node->right()->is_typed(cdk::TYPE_INT)) ||
           (node->left()->is_typed(cdk::TYPE_POINTER) && node->right()->is_typed(cdk::TYPE_POINTER)))
    node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
  else
    throw std::string("wrong type in arguments of binary expression");
}

//---------------------------------------------------------------------------
void fir::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  processBinaryExpressionIntDouble(node, lvl);
}
void fir::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
   processBinaryExpressionIntDouble(node, lvl);
}
void fir::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
   processBinaryExpressionInt(node, lvl);
}

//---------------------------------------------------------------------------
void fir::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
   processBinaryExpressionIntDoublePointer(node, lvl);
}
void fir::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  processBinaryExpressionIntDoublePointer(node, lvl);
}

//---------------------------------------------------------------------------
void fir::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
  processBinaryExpressionIntDouble(node, lvl);
}
void fir::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
  processBinaryExpressionIntDouble(node, lvl);
}
void fir::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
  processBinaryExpressionIntDouble(node, lvl);
}
void fir::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
  processBinaryExpressionIntDouble(node, lvl);
}

//---------------------------------------------------------------------------
void fir::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
  processBinaryExpressionIntDoublePointer(node, lvl);
}
void fir::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
  processBinaryExpressionIntDoublePointer(node, lvl);
}

//---------------------------------------------------------------------------
void fir::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  processBinaryExpressionInt(node, lvl);
}
void fir::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  processBinaryExpressionInt(node, lvl);
}

//---------------------------------------------------------------------------
void fir::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  std::shared_ptr<fir::symbol> symbol = _symtab.find(id);
  if (symbol == nullptr) {
    throw "id '" + id + "' is not declared"; 
  }
  else {
    node->type(symbol->type());
  }
}

void fir::type_checker::do_variable_definition_node(fir::variable_definition_node *const node, int lvl) {
  if(node->initializer() == nullptr){
    const std::string &id = node->identifier();

    std::shared_ptr<fir::symbol> symbol = std::make_shared<fir::symbol> (
      node->type(), // type
      node->qualifier(), // qualifiers: public, declared, "private" (i.e., none)
      id, // identifier
      false,
      false
      ); 
    if (_symtab.insert(id, symbol)) {
      _parent->set_new_symbol(symbol); 
    } 
    else {
      throw std::string("variable '" + id + "' redeclared");
    }
  }

  else {
    node->initializer()->accept(this, lvl);
    if (node->initializer()->is_typed(cdk::TYPE_UNSPEC)) { 
      fir::read_node *read = dynamic_cast<fir::read_node*>(node->initializer());
      fir::stack_alloc_node *stack = dynamic_cast<fir::stack_alloc_node*>(node->initializer());
      if(read != nullptr) {
        if(node->is_typed(cdk::TYPE_INT) || node->is_typed(cdk::TYPE_DOUBLE))
          node->initializer()->type(node->type());
        else
          throw std::string("wrong type in input");
      }
      else if (stack != nullptr) {
        if (node->is_typed(cdk::TYPE_POINTER))
          node->initializer()->type(node->type());
        else
          throw std::string("wrong type in allocation");
      }
      else
        throw std::string("type unspecified");
    }
    else if (node->is_typed(cdk::TYPE_INT)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT))
        throw std::string("expected integer for initializer");
    }

    else if (node->is_typed(cdk::TYPE_DOUBLE)) {
      if (!(node->initializer()->is_typed(cdk::TYPE_DOUBLE) ||
           node->initializer()->is_typed(cdk::TYPE_INT)))
            throw std::string("expected double or integer for initializer");
    }

    else if (node->is_typed(cdk::TYPE_STRING)) {
      if (!node->initializer()->is_typed(cdk::TYPE_STRING))
        throw std::string("expected string for initializer");
    }

    else if (node->is_typed(cdk::TYPE_POINTER)) {
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)){
        throw std::string("expected pointer for initializer");
      }
    }

    else {
      throw std::string("unknown type for initializer");
    }
    
    const std::string &id = node->identifier();
    std::shared_ptr<fir::symbol> symbol = std::make_shared<fir::symbol> (
        node->type(), 
        node->qualifier(), // qualifiers: public, require
        id, // identifier
        true,
        false
        );
    if (_symtab.insert(id, symbol)) {
      _parent->set_new_symbol(symbol); 
    } 
    else {
        throw std::string("variable '" + id + "' redeclared");
    }
  }
}

void fir::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl);
  node->type(node->lvalue()->type()); 
}

void fir::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl);
  node->rvalue()->accept(this, lvl);

  if(node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node*>(node->rvalue());
    fir::stack_alloc_node *stack = dynamic_cast<fir::stack_alloc_node*>(node->rvalue());

    if(stack != nullptr && node->lvalue()->is_typed(cdk::TYPE_POINTER)) {
        node->rvalue()->type(node->lvalue()->type());
    }
    else if(read != nullptr && 
      (node->lvalue()->is_typed(cdk::TYPE_INT) || node->lvalue()->is_typed(cdk::TYPE_DOUBLE))) {
        node->rvalue()->type(node->lvalue()->type());
    }
    else {
      throw std::string("wrong assignment to left value");
    }
  }
  else if (node->lvalue()->is_typed(cdk::TYPE_INT)) {
    if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } 
    else {
      throw std::string("wrong assignment to integer");
    }
  } 
  else if (node->lvalue()->is_typed(cdk::TYPE_POINTER)) {
    if (node->rvalue()->is_typed(cdk::TYPE_POINTER)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
    } 
    else {
      throw std::string("wrong assignment to pointer");
    }
  } 
  else if (node->lvalue()->is_typed(cdk::TYPE_DOUBLE)) {
    if (node->rvalue()->is_typed(cdk::TYPE_DOUBLE) || node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } 
    else {
      throw std::string("wrong assignment to real");
    }
  } 
  else if (node->lvalue()->is_typed(cdk::TYPE_STRING)) {
    if (node->rvalue()->is_typed(cdk::TYPE_STRING)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } 
    else {
      throw std::string("wrong assignment to string");
    }
  }
  else {
    node->type(cdk::primitive_type::create(node->rvalue()->type()->size(), node->rvalue()->type()->name()));
  }
}

//---------------------------------------------------------------------------
void fir::type_checker::do_evaluation_node(fir::evaluation_node *const node, int lvl) {
  node->argument()->accept(this, lvl);

  if(node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node*>(node->argument());

    if(read == nullptr) {
      throw std::string("type unspecified");
    }
    node->argument()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE)); 
  }
}

void fir::type_checker::do_stack_alloc_node(fir::stack_alloc_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl);

  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
  }
  else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node*>(node->argument());

    if(read == nullptr){
      throw std::string("type unspecified");
    }
    node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
    node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT)); 
  }
  else {
    throw std::string("integer expression expected in allocation");
  }
  
}

void fir::type_checker::do_index_node(fir::index_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->base()->accept(this, lvl);
  if (!node->base()->is_typed(cdk::TYPE_POINTER))
    throw std::string("base must be a pointer");

  node->index()->accept(this, lvl + 2);
  if(node->index()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node *>(node->index());

    if(read == nullptr)
      throw std::string("type unspecified");
    node->index()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  }
  else if (!node->index()->is_typed(cdk::TYPE_INT))
    throw std::string("index must be an integer");

  node->type(cdk::reference_type::cast(node->base()->type())->referenced()); 
}

void fir::type_checker::do_sizeof_node(fir::sizeof_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->expression()->accept(this, lvl);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}


//---------------------------------------------------------------------------

void fir::type_checker::do_while_node(fir::while_node *const node, int lvl) {
  node->condition()->accept(this, lvl);
  if (!node->condition()->is_typed(cdk::TYPE_INT))
    throw std::string("expected integer type condition");
}
void fir::type_checker::do_while_finally_node(fir::while_finally_node * const node, int lvl) {
  node->condition()->accept(this, lvl);
  if (!node->condition()->is_typed(cdk::TYPE_INT))
    throw std::string("expected integer type condition");
}
void fir::type_checker::do_leave_node(fir::leave_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_restart_node(fir::restart_node *const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

void fir::type_checker::do_if_node(fir::if_node *const node, int lvl) {
  node->condition()->accept(this, lvl);
  if (!node->condition()->is_typed(cdk::TYPE_INT))
    throw std::string("expected integer type condition");
}

void fir::type_checker::do_if_else_node(fir::if_else_node *const node, int lvl) {
  node->condition()->accept(this, lvl);
  if (!node->condition()->is_typed(cdk::TYPE_INT))
    throw std::string("expected integer,type condition");
}

//---------------------------------------------------------------------------


void fir::type_checker::do_body_node(fir::body_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_prologue_node(fir::prologue_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_block_node(fir::block_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_function_declaration_node(fir::function_declaration_node *const node, int lvl) {
  std::string id;

  if (node->identifier() == "fir")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id = node->identifier();

  std::shared_ptr<fir::symbol> function = std::make_shared<fir::symbol> (
        node->type(), 
        node->qualifier(), 
        id, 
        false,
        true);

  function->set_offset(-node->type()->size());

  std::vector<std::shared_ptr<cdk::basic_type>> argtypes;
  for (size_t arg = 0; arg < node->arguments()->size(); arg++)
    argtypes.push_back(node->argument(arg)->type());
  function->set_arguments_types(argtypes);

  std::shared_ptr<fir::symbol> previous = _symtab.find(function->identifier());
  if (previous) {
    throw std::string("conflicting declaration for '" + function->identifier() + "'");
  }
  else {
    _symtab.insert(function->identifier(), function);
    _parent->set_new_symbol(function);
  }

}

void fir::type_checker::do_function_definition_node(fir::function_definition_node *const node, int lvl) {
  std::string id;

  if (node->identifier() == "fir")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id = node->identifier();

  std::shared_ptr<fir::symbol> function = std::make_shared<fir::symbol> (
        node->type(), 
        node->qualifier(), 
        id, 
        true,
        true);

  function->set_offset(-node->type()->size());

  std::vector<std::shared_ptr<cdk::basic_type>> argtypes;
  for (size_t arg = 0; arg < node->arguments()->size(); arg++)
    argtypes.push_back(node->argument(arg)->type());
  function->set_arguments_types(argtypes);

  std::shared_ptr<fir::symbol> previous = _symtab.find(function->identifier());

  if (node->default_return_value()) {
    if (function->type()->name() == cdk::TYPE_VOID)
      throw std::string("initializer specified for void function.");

    node->default_return_value()->accept(this, lvl + 2);

    if (function->type()->name() == cdk::TYPE_INT) {
      if (node->default_return_value()->type()->name() != cdk::TYPE_INT) throw std::string(
          "wrong type for initializer (integer expected).");
    } 
    else if (function->type()->name() == cdk::TYPE_DOUBLE) {
      if (node->default_return_value()->type()->name() != cdk::TYPE_INT
          && node->default_return_value()->type()->name() != cdk::TYPE_DOUBLE) throw std::string(
          "wrong type for initializer (integer or double expected).");
    } 
    else if (function->type()->name() == cdk::TYPE_STRING) {
      if (node->default_return_value()->type()->name() != cdk::TYPE_STRING) throw std::string(
          "wrong type for initializer (string expected).");
    } 
    else {
      throw std::string("unknown type for initializer.");
    }
  }
  
  if (previous) {
    if (!previous->function()) {
      throw std::string("'" + function->identifier() + "' already declared as variable");
    }
    else if (previous->initialized()) {
      throw std::string("'" + function->identifier() + "' already initialized");
    }
    else if (previous->type()->name() != function->type()->name()){
      throw std::string("conflicting declaration for '" + function->identifier() + "'");
    }
    _symtab.replace(function->identifier(), function);
    _parent->set_new_symbol(function);
  }
  else {
    _symtab.insert(function->identifier(), function);
    _parent->set_new_symbol(function);
  }

}

void fir::type_checker::do_function_call_node(fir::function_call_node *const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->identifier();
  std::shared_ptr<fir::symbol> function = _symtab.find(id);

  if (function == nullptr){
    throw std::string("function '" + id + "' is not declared");
  }
  else if (!function->function()){
    throw std::string("function '" + id + "' is not a function");
  } 

  node->type(function->type());
  if (node->arguments()->size() != 0 && function->number_of_arguments() != 0) {
    node->arguments()->accept(this, lvl);

    if (node->arguments()->size() != function->number_of_arguments()) {
      throw std::string("'" + function->identifier() + "' number of arguments in call are different");
    } 
    else {
      for(size_t arg = 0; arg < node->arguments()->size(); arg++){
        if (node->argument(arg)->type()->name() != function->arguments_types().at(arg)->name()) {
          throw std::string("'" + function->identifier() + "' arguments types in call do not match");
        }
      }
    }
  }
}

void fir::type_checker::do_return_node(fir::return_node *const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------
void fir::type_checker::do_write_node(fir::write_node * const node, int lvl) {
  for(size_t i = 0; i < node->arguments()->size(); i++) {
    cdk::expression_node *expression = dynamic_cast<cdk::expression_node *>(node->arguments()->node(i));
    expression->accept(this, lvl);
    if (!expression->is_typed(cdk::TYPE_INT) &&
        !expression->is_typed(cdk::TYPE_DOUBLE) &&
        !expression->is_typed(cdk::TYPE_STRING)){
          throw std::string("wrong type in argument");
    }
  }
}

void fir::type_checker::do_read_node(fir::read_node * const node, int lvl) {
  node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
}
