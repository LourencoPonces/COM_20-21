#ifndef __PF2ASM_AST_ARITHMETIC_DNEG_H__
#define __PF2ASM_AST_ARITHMETIC_DNEG_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DNEG: public cdk::basic_node {
  public:
    DNEG(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DNEG(this, level);
    }
  };

} // pf2asm

#endif
