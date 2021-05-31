#ifndef __PF2ASM_AST_ADDRESSING_ALIGN_H__
#define __PF2ASM_AST_ADDRESSING_ALIGN_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class ALIGN: public cdk::basic_node {
  public:
    ALIGN(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_ALIGN(this, level);
    }
  };

} // pf2asm

#endif
