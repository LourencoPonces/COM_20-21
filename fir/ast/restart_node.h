#ifndef __FIR_AST_NEXT_H__
#define __FIR_AST_NEXT_H__

#include <cdk/ast/basic_node.h>

namespace fir {

  class restart_node: public cdk::basic_node {
    int _nCycle;

  public:
    restart_node(int lineno, int nCycle = 1) :
        cdk::basic_node(lineno), _nCycle(nCycle) {
    }

  public:
    int nCycle() const {
      return _nCycle;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_restart_node(this, level);
    }

  };

} // fir

#endif
