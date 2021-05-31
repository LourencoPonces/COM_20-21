#ifndef __PF2ASM_AST_FUNCTION_STFVAL32_H__
#define __PF2ASM_AST_FUNCTION_STFVAL32_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class STFVAL32: public cdk::basic_node {
  public:
    STFVAL32(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_STFVAL32(this, level);
    }
  };

} // pf2asm

#endif
