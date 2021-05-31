#ifndef __PF2ASM_AST_SP_H__
#define __PF2ASM_AST_SP_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SP: public cdk::basic_node {
  public:
    SP(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SP(this, level);
    }
  };

} // pf2asm

#endif
