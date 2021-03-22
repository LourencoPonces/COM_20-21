#ifndef __FIR_AST_STOP_H__
#define __FIR_AST_STOP_H__

#include <cdk/ast/basic_node.h>

namespace fir {

  class leave_node: public cdk::basic_node {
    int _nCycle;

  public:
    leave_node(int lineno, int nCycle = 1) :
        cdk::basic_node(lineno), _nCycle(nCycle) {
    }

  public:
    int nCycle() const {
      return _nCycle;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_leave_node(this, level);
    }

  };

} // fir

#endif
