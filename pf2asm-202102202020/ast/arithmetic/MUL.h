#ifndef __PF2ASM_AST_ARITHMETIC_MUL_H__
#define __PF2ASM_AST_ARITHMETIC_MUL_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class MUL: public cdk::basic_node {
  public:
    MUL(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_MUL(this, level);
    }
  };

} // pf2asm

#endif
