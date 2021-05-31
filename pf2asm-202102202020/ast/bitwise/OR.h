#ifndef __PF2ASM_AST_BITWISE_OR_H__
#define __PF2ASM_AST_BITWISE_OR_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class OR: public cdk::basic_node {
  public:
    OR(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_OR(this, level);
    }
  };

} // pf2asm

#endif
