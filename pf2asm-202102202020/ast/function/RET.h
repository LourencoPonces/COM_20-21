#ifndef __PF2ASM_AST_FUNCTION_RET_H__
#define __PF2ASM_AST_FUNCTION_RET_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class RET: public cdk::basic_node {
  public:
    RET(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_RET(this, level);
    }
  };

} // pf2asm

#endif
