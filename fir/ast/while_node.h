#ifndef __FIR_AST_WHILE_NODE_H__
#define __FIR_AST_WHILE_NODE_H__

#include <cdk/ast/expression_node.h>

namespace fir {

  /**
   * Class for describing while-cycle nodes.
   */
  class while_node: public cdk::basic_node {
    cdk::expression_node *_condition;
    cdk::basic_node *_doblock;

  public:
    while_node(int lineno, cdk::expression_node *condition, cdk::basic_node *doblock) :
        basic_node(lineno), _condition(condition), _doblock(doblock) {
    }

  public:
    cdk::expression_node *condition() {
      return _condition;
    }
    cdk::basic_node *doblock() {
      return _doblock;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_while_node(this, level);
    }

  };

} // fir

#endif
