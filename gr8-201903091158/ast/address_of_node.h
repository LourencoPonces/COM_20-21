#ifndef __GR8_AST_ADDRESS_OF_H__
#define __GR8_AST_ADDRESS_OF_H__

#include <cdk/ast/unary_expression_node.h>
#include "targets/basic_ast_visitor.h"

namespace gr8 {

  class address_of_node: public cdk::expression_node {
    cdk::lvalue_node *_lvalue;

  public:
    address_of_node(int lineno, cdk::lvalue_node *argument) :
        cdk::expression_node(lineno), _lvalue(argument) {
    }

  public:
    cdk::lvalue_node *lvalue() {
      return _lvalue;
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_address_of_node(this, level);
    }

  };

} // gr8

#endif
