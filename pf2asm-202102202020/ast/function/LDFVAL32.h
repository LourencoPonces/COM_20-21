#ifndef __PF2ASM_AST_FUNCTION_LDFVAL32_H__
#define __PF2ASM_AST_FUNCTION_LDFVAL32_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LDFVAL32: public cdk::basic_node {
  public:
    LDFVAL32(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LDFVAL32(this, level);
    }
  };

} // pf2asm

#endif
