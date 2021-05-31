#ifndef __FIR_AST_WRITE_NODE_H__
#define __FIR_AST_WRITE_NODE_H__

#include <cdk/ast/sequence_node.h>

namespace fir {

  /**
   * Class for describing write nodes.
   */
  class write_node: public cdk::basic_node {
    cdk::sequence_node *_arguments;
    bool _newL;

  public:
    write_node(int lineno, cdk::sequence_node *arguments, bool newL) :
        cdk::basic_node(lineno), _arguments(arguments), _newL(newL) {
    }

  public:
    cdk::sequence_node *arguments() {
      return _arguments;
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
