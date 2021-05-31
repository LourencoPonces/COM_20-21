#ifndef __PF2ASM_AST_JUMPS_BRANCH_H__
#define __PF2ASM_AST_JUMPS_BRANCH_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class BRANCH: public cdk::basic_node {
  public:
    BRANCH(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_BRANCH(this, level);
    }
  };

} // pf2asm

#endif
