#ifndef __PF2ASM_AST_F2D_H__
#define __PF2ASM_AST_F2D_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class F2D: public cdk::basic_node {
  public:
    F2D(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_F2D(this, level);
    }
  };

} // pf2asm

#endif
