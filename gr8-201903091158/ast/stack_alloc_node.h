#ifndef __GR8_AST_STACK_ALLOC_H__
#define __GR8_AST_STACK_ALLOC_H__

#include <cdk/ast/unary_expression_node.h>
#include "targets/basic_ast_visitor.h"

namespace gr8 {

  class stack_alloc_node: public cdk::unary_expression_node {
  public:
    stack_alloc_node(int lineno, cdk::expression_node *argument) :
        cdk::unary_expression_node(lineno, argument) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stack_alloc_node(this, level);
    }

  };

} // gr8

#endif
