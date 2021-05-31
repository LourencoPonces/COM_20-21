#ifndef __PF2ASM_AST_RELATIONAL_ULT_H__
#define __PF2ASM_AST_RELATIONAL_ULT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class ULT: public cdk::basic_node {
  public:
    ULT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_ULT(this, level);
    }
  };

} // pf2asm

#endif
