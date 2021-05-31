#ifndef __PF2ASM_AST_ARITHMETIC_ADD_H__
#define __PF2ASM_AST_ARITHMETIC_ADD_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class ADD: public cdk::basic_node {
  public:
    ADD(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_ADD(this, level);
    }
  };

} // pf2asm

#endif
