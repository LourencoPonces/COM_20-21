#ifndef __PF2ASM_AST_FUNCTION_LEAVE_H__
#define __PF2ASM_AST_FUNCTION_LEAVE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LEAVE: public cdk::basic_node {
  public:
    LEAVE(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LEAVE(this, level);
    }
  };

} // pf2asm

#endif
