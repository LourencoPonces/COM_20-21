#ifndef __PF2ASM_AST_ADDRESSING_BSS_H__
#define __PF2ASM_AST_ADDRESSING_BSS_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class BSS: public cdk::basic_node {
  public:
    BSS(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_BSS(this, level);
    }
  };

} // pf2asm

#endif
