#ifndef __PF2ASM_AST_RELATIONAL_LT_H__
#define __PF2ASM_AST_RELATIONAL_LT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LT: public cdk::basic_node {
  public:
    LT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LT(this, level);
    }
  };

} // pf2asm

#endif
