#ifndef __PF2ASM_AST_ARITHMETIC_DIV_H__
#define __PF2ASM_AST_ARITHMETIC_DIV_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DIV: public cdk::basic_node {
  public:
    DIV(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DIV(this, level);
    }
  };

} // pf2asm

#endif
