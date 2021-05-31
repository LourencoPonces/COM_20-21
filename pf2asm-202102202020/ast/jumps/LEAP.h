#ifndef __PF2ASM_AST_JUMPS_LEAP_H__
#define __PF2ASM_AST_JUMPS_LEAP_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LEAP: public cdk::basic_node {
  public:
    LEAP(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LEAP(this, level);
    }
  };

} // pf2asm

#endif
