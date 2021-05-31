#ifndef __PF2ASM_AST_RELATIONAL_GE_H__
#define __PF2ASM_AST_RELATIONAL_GE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class GE: public cdk::basic_node {
  public:
    GE(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_GE(this, level);
    }
  };

} // pf2asm

#endif
