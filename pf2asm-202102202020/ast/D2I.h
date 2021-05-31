#ifndef __PF2ASM_AST_D2I_H__
#define __PF2ASM_AST_D2I_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class D2I: public cdk::basic_node {
  public:
    D2I(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_D2I(this, level);
    }
  };

} // pf2asm

#endif
