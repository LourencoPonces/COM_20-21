#ifndef __PF2ASM_AST_ARITHMETIC_DMUL_H__
#define __PF2ASM_AST_ARITHMETIC_DMUL_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DMUL: public cdk::basic_node {
  public:
    DMUL(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DMUL(this, level);
    }
  };

} // pf2asm

#endif
