#ifndef __PF2ASM_AST_NIL_H__
#define __PF2ASM_AST_NIL_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class NIL: public cdk::basic_node {
  public:
    NIL(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_NIL(this, level);
    }
  };

} // pf2asm

#endif
