#ifndef __PF2ASM_AST_FUNCTION_START_H__
#define __PF2ASM_AST_FUNCTION_START_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class START: public cdk::basic_node {
  public:
    START(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_START(this, level);
    }
  };

} // pf2asm

#endif
