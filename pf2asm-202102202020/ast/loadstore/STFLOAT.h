#ifndef __PF2ASM_AST_LOADSTORE_STFLOAT_H__
#define __PF2ASM_AST_LOADSTORE_STFLOAT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class STFLOAT: public cdk::basic_node {
  public:
    STFLOAT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_STFLOAT(this, level);
    }
  };

} // pf2asm

#endif
