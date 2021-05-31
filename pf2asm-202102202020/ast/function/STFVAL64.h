#ifndef __PF2ASM_AST_FUNCTION_STFVAL64_H__
#define __PF2ASM_AST_FUNCTION_STFVAL64_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class STFVAL64: public cdk::basic_node {
  public:
    STFVAL64(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_STFVAL64(this, level);
    }
  };

} // pf2asm

#endif
