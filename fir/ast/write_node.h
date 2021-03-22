#ifndef __FIR_AST_WRITE_NODE_H__
#define __FIR_AST_WRITE_NODE_H__

#include <cdk/ast/expression_node.h>

namespace fir {

  /**
   * Class for describing write nodes.
   */
  class write_node: public cdk::basic_node {
    cdk::expression_node *_argument;
    bool _newL;

  public:
    write_node(int lineno, cdk::expression_node *argument, bool newL) :
        cdk::basic_node(lineno), _argument(argument), _newL(newL) {
    }

  public:
    cdk::expression_node *argument() {
      return _argument;
    }
    bool newL(){
      return _newL;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_write_node(this, level);
    }

  };

} // fir

#endif
