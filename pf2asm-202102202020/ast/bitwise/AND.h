#ifndef __PF2ASM_AST_BITWISE_AND_H__
#define __PF2ASM_AST_BITWISE_AND_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class AND: public cdk::basic_node {
  public:
    AND(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_AND(this, level);
    }
  };

} // pf2asm

#endif
