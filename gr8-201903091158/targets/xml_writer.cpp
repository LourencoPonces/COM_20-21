#include <string>
#include <iostream>
#include "targets/type_checker.h"
#include "targets/xml_writer.h"
#include "targets/symbol.h"
#include "ast/all.h"
// must come after other #includes
#include "gr8_parser.tab.h"

static std::string type_name(basic_type *type) {
  if (type->name() == basic_type::TYPE_INT) return "integer";
  if (type->name() == basic_type::TYPE_DOUBLE) return "double";
  if (type->name() == basic_type::TYPE_STRING) return "string";
  if (type->name() == basic_type::TYPE_VOID) return "void";
  if (type->name() == basic_type::TYPE_POINTER) {
    std::string s = "pointer";
    basic_type *p = type->subtype();
    while (p != nullptr) {
      s += " to " + type_name(p);
      p = p->subtype();
    }
    return s;
  } else
    return "unknown type";
}

static std::string qualifier_name(int qualifier) {
  if (qualifier == tPUBLIC) return "public";
  if (qualifier == tPRIVATE)
    return "private";
  else
    return "unknown qualifier";
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}

void gr8::xml_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<" << node->label() << " size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++) {
    cdk::basic_node *n = node->node(i);
    if (n == NULL) break;
    n->accept(this, lvl + 2);
  }
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_double_node(cdk::double_node * const node, int lvl) {
  do_literal_node(node, lvl);
}

void gr8::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  do_literal_node(node, lvl);
}

void gr8::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  do_literal_node(node, lvl);
}

//---------------------------------------------------------------------------
//protected:
void gr8::xml_writer::do_unary_expression_node(cdk::unary_expression_node * const node, int lvl) {
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_binary_expression_node(cdk::binary_expression_node * const node, int lvl) {
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------
//public:
void gr8::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  do_unary_expression_node(node, lvl);
}

//---------------------------------------------------------------------------
//public:
void gr8::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}

//===========================================================================

void gr8::xml_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->name() << "</" << node->label() << ">" << std::endl;
}

void gr8::xml_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE;
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE;
  os() << std::string(lvl, ' ') << "<assignment>" << std::endl;
  node->lvalue()->accept(this, lvl + 2);
  node->rvalue()->accept(this, lvl + 2);
  os() << std::string(lvl, ' ') << "</assignment>" << std::endl;
}

//===========================================================================

void gr8::xml_writer::do_or_node(cdk::or_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_and_node(cdk::and_node * const node, int lvl) {
  do_binary_expression_node(node, lvl);
}
void gr8::xml_writer::do_not_node(cdk::not_node * const node, int lvl) {
  do_unary_expression_node(node, lvl);
}

void gr8::xml_writer::do_print_node(gr8::print_node * const node, int lvl) {
  ASSERT_SAFE;

  std::string argtype = "";
  if (node->argument()->type()->name() == basic_type::TYPE_INT)
  argtype = "integer";
  else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE)
  argtype = "real";
  else if (node->argument()->type()->name() == basic_type::TYPE_STRING)
  argtype = "string";
  else if (node->argument()->type()->name() == basic_type::TYPE_POINTER)
  argtype = "pointer";
  else
  argtype = "unknown type";
  os() << std::string(lvl, ' ') << "<" << node->label() << " type='" << argtype << "'>" << std::endl;
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_read_node(gr8::read_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_evaluation_node(gr8::evaluation_node * const node, int lvl) {
  openTag(node, lvl);
  node->expression()->accept(this, lvl);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_block_node(gr8::block_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("declarations", lvl);
  if (node->declarations()) {
    node->declarations()->accept(this, lvl + 4);
  }
  closeTag("declarations", lvl);
  openTag("instructions", lvl);
  if (node->instructions()) {
    node->instructions()->accept(this, lvl + 4);
  }
  closeTag("instructions", lvl);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_left_index_node(gr8::left_index_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("base", lvl);
  node->base()->accept(this, lvl + 2);
  closeTag("base", lvl);
  openTag("index", lvl);
  node->index()->accept(this, lvl + 2);
  closeTag("index", lvl);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_address_of_node(gr8::address_of_node * const node, int lvl) {
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_stack_alloc_node(gr8::stack_alloc_node * const node, int lvl) {
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_nullptr_node(gr8::nullptr_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_sweep_node(gr8::sweep_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<" << node->label() << ">"
       << std::endl;
  openTag("left-value", lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag("left-value", lvl);
  openTag("lower-bound", lvl);
  node->begin()->accept(this, lvl + 4);
  closeTag("lower-bound", lvl);
  openTag("upper-bound", lvl);
  node->end()->accept(this, lvl + 4);
  closeTag("upper-bound", lvl);
  openTag("step", lvl);
  node->step()->accept(this, lvl + 4);
  closeTag("step", lvl);
  openTag("instruction", lvl);
  node->instruction()->accept(this, lvl + 4);
  closeTag("instruction", lvl);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_stop_node(gr8::stop_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_next_node(gr8::next_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_if_node(gr8::if_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl);
  openTag("then", lvl);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_if_else_node(gr8::if_else_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl);
  openTag("then", lvl);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl);
  if (node->elseblock()) {
    openTag("else", lvl);
    node->elseblock()->accept(this, lvl + 4);
    closeTag("else", lvl);
  }
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_function_call_node(gr8::function_call_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<" << node->label() << " name='" << node->identifier() << "'>" << std::endl;
  openTag("arguments", lvl);
  if (node->arguments()) node->arguments()->accept(this, lvl + 4);
  closeTag("arguments", lvl);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_function_declaration_node(gr8::function_declaration_node * const node, int lvl) {
  if (_inFunctionBody || _inFunctionArgs) {
    error(node->lineno(), "cannot declare function in body or in args");
    return;
  }

  //DAVID: FIXME: should be at the beginning
  ASSERT_SAFE;
  reset_new_symbol();

  os() << std::string(lvl, ' ') << "<" << node->label() << " name='" << node->identifier() << "' qualifier='"
       << qualifier_name(node->qualifier()) << "' type='" << type_name(node->type()) << "'>" << std::endl;

  openTag("arguments", lvl);
  if (node->arguments()) {
    _symtab.push();
    node->arguments()->accept(this, lvl + 4);
    _symtab.pop();
  }
  closeTag("arguments", lvl);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_function_definition_node(gr8::function_definition_node * const node, int lvl) {
  if (_inFunctionBody || _inFunctionArgs) {
    error(node->lineno(), "cannot define function in body or in args");
    return;
  }

  //DAVID: FIXME: should be at the beginning
  ASSERT_SAFE;

  // remember symbol so that args and body know
  _function = new_symbol();
  reset_new_symbol();

  _inFunctionBody = true;
  _symtab.push(); // scope of args

  os() << std::string(lvl, ' ') << "<" << node->label() << " name='" << node->identifier() << "' qualifier='"
       << qualifier_name(node->qualifier()) << "' type='" << type_name(node->type()) << "'>" << std::endl;

  openTag("arguments", lvl);
  if (node->arguments()) {
    _inFunctionArgs = true; //FIXME really needed?
    node->arguments()->accept(this, lvl + 4);
    _inFunctionArgs = false; //FIXME really needed?
  }
  closeTag("arguments", lvl);
  node->block()->accept(this, lvl + 2);
  closeTag(node, lvl);

  _symtab.pop(); // scope of args
  _inFunctionBody = false;
}

void gr8::xml_writer::do_return_node(gr8::return_node * const node, int lvl) {
  ASSERT_SAFE;

  openTag(node, lvl);
  if (node->retval())
    node->retval()->accept(this, lvl+4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_variable_declaration_node(gr8::variable_declaration_node * const node, int lvl) {
  ASSERT_SAFE;
  reset_new_symbol();

  os() << std::string(lvl, ' ') << "<" << node->label() << " name='" << node->identifier() << "' qualifier='"
  << qualifier_name(node->qualifier()) << "' type='" << type_name(node->varType()) << "'>"
  << std::endl;

  if (node->initializer()) {
    openTag("initializer", lvl);
    node->initializer()->accept(this, lvl + 4);
    closeTag("initializer", lvl);
  }
  closeTag(node, lvl);
}
