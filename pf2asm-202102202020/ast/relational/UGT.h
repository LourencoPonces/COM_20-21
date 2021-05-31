#ifndef __PF2ASM_AST_RELATIONAL_UGT_H__
#define __PF2ASM_AST_RELATIONAL_UGT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class UGT: public cdk::basic_node {
  public:
    UGT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_UGT(this, level);
    }
  };

} // pf2asm

#endif
