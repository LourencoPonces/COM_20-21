#ifndef __PF2ASM_AST_RELATIONAL_UGE_H__
#define __PF2ASM_AST_RELATIONAL_UGE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class UGE: public cdk::basic_node {
  public:
    UGE(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_UGE(this, level);
    }
  };

} // pf2asm

#endif
