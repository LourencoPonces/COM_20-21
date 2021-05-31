#ifndef __PF2ASM_AST_RELATIONAL_NE_H__
#define __PF2ASM_AST_RELATIONAL_NE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class NE: public cdk::basic_node {
  public:
    NE(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_NE(this, level);
    }
  };

} // pf2asm

#endif
