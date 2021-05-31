#ifndef __PF2ASM_AST_LOADSTORE_LDFLOAT_H__
#define __PF2ASM_AST_LOADSTORE_LDFLOAT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LDFLOAT: public cdk::basic_node {
  public:
    LDFLOAT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LDFLOAT(this, level);
    }
  };

} // pf2asm

#endif
