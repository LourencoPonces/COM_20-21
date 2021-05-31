#ifndef __PF2ASM_AST_ARITHMETIC_MOD_H__
#define __PF2ASM_AST_ARITHMETIC_MOD_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class MOD: public cdk::basic_node {
  public:
    MOD(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_MOD(this, level);
    }
  };

} // pf2asm

#endif
