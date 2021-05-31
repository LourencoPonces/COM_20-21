#ifndef __PF2ASM_AST_ARITHMETIC_UDIV_H__
#define __PF2ASM_AST_ARITHMETIC_UDIV_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class UDIV: public cdk::basic_node {
  public:
    UDIV(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_UDIV(this, level);
    }
  };

} // pf2asm

#endif
