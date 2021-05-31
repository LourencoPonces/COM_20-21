#ifndef __GR8_AST_NULLPTR_H__
#define __GR8_AST_NULLPTR_H__

#include <cdk/ast/expression_node.h>

namespace gr8 {

  class nullptr_node: public cdk::expression_node {
  public:
    nullptr_node(int lineno) :
        cdk::expression_node(lineno) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_nullptr_node(this, level);
    }

  };

} // gr8

#endif
