#ifndef __PF2ASM_AST_D2F_H__
#define __PF2ASM_AST_D2F_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class D2F: public cdk::basic_node {
  public:
    D2F(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_D2F(this, level);
    }
  };

} // pf2asm

#endif
