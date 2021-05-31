#ifndef __PF2ASM_AST_ARITHMETIC_DDIV_H__
#define __PF2ASM_AST_ARITHMETIC_DDIV_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DDIV: public cdk::basic_node {
  public:
    DDIV(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DDIV(this, level);
    }
  };

} // pf2asm

#endif
