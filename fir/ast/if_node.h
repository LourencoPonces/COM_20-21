#ifndef __FIR_AST_IF_NODE_H__
#define __FIR_AST_IF_NODE_H__

#include <cdk/ast/expression_node.h>

namespace fir {

  /**
   * Class for describing if-then nodes.
   */
  class if_node: public cdk::basic_node {
    cdk::expression_node *_condition;
    cdk::basic_node *_thenblock;

  public:
    if_node(int lineno, cdk::expression_node *condition, cdk::basic_node *thenblock) :
        cdk::basic_node(lineno), _condition(condition), _thenblock(thenblock) {
    }

  public:
    cdk::expression_node *condition() {
      return _condition;
    }
    cdk::basic_node *thenblock() {
      return _thenblock;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_if_node(this, level);
    }

  };

} // fir

#endif
