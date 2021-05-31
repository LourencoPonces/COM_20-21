#ifndef __GR8_AST_LEFT_INDEX_H__
#define __GR8_AST_LEFT_INDEX_H__

#include <cdk/ast/lvalue_node.h>
#include "targets/basic_ast_visitor.h"

namespace gr8 {

  class left_index_node: public cdk::lvalue_node {
    cdk::expression_node *_base;
    cdk::expression_node *_index;

  public:
    left_index_node(int lineno, cdk::expression_node *base, cdk::expression_node *index) :
        cdk::lvalue_node(lineno), _base(base), _index(index) {
    }

  public:
    cdk::expression_node *base() {
      return _base;
    }
    cdk::expression_node *index() {
      return _index;
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_left_index_node(this, level);
    }

  };

} // gr8

#endif
