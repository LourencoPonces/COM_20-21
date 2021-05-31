#include <string>
#include "targets/frame_size_calculator.h"
#include "targets/symbol.h"
#include "ast/all.h"

gr8::frame_size_calculator::~frame_size_calculator() {
  os().flush();
}

void gr8::frame_size_calculator::do_add_node(cdk::add_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_and_node(cdk::and_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_div_node(cdk::div_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_double_node(cdk::double_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_eq_node(cdk::eq_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_ge_node(cdk::ge_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_gt_node(cdk::gt_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_integer_node(cdk::integer_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_le_node(cdk::le_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_lt_node(cdk::lt_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_mod_node(cdk::mod_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_mul_node(cdk::mul_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_ne_node(cdk::ne_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_neg_node(cdk::neg_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_not_node(cdk::not_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_or_node(cdk::or_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_string_node(cdk::string_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_sub_node(cdk::sub_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_evaluation_node(gr8::evaluation_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_print_node(gr8::print_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_read_node(gr8::read_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_address_of_node(gr8::address_of_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_function_call_node(gr8::function_call_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_function_declaration_node(gr8::function_declaration_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_left_index_node(gr8::left_index_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_next_node(gr8::next_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_nullptr_node(gr8::nullptr_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_return_node(gr8::return_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_stack_alloc_node(gr8::stack_alloc_node * const node, int lvl) {
  // EMPTY
}
void gr8::frame_size_calculator::do_stop_node(gr8::stop_node * const node, int lvl) {
  // EMPTY
}

void gr8::frame_size_calculator::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    cdk::basic_node *n = node->node(i);
    if (n == nullptr) break;
    n->accept(this, lvl + 2);
  }
}

void gr8::frame_size_calculator::do_block_node(gr8::block_node * const node, int lvl) {
  if (node->declarations()) node->declarations()->accept(this, lvl + 2);
  if (node->instructions()) node->instructions()->accept(this, lvl + 2);
}

void gr8::frame_size_calculator::do_sweep_node(gr8::sweep_node * const node, int lvl) {
  node->instruction()->accept(this, lvl + 2);
}

void gr8::frame_size_calculator::do_if_node(gr8::if_node * const node, int lvl) {
  node->block()->accept(this, lvl + 2);
}

void gr8::frame_size_calculator::do_if_else_node(gr8::if_else_node * const node, int lvl) {
  node->thenblock()->accept(this, lvl + 2);
  if (node->elseblock()) node->elseblock()->accept(this, lvl + 2);
}

void gr8::frame_size_calculator::do_variable_declaration_node(gr8::variable_declaration_node * const node, int lvl) {
  _localsize += node->varType()->size();
}

void gr8::frame_size_calculator::do_function_definition_node(gr8::function_definition_node * const node, int lvl) {
  _localsize += node->type()->size(); // save space for the function's return type
  node->block()->accept(this, lvl + 2);
}
