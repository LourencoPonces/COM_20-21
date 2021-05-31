#ifndef __PF2ASM_AST_ADDRESSING_RODATA_H__
#define __PF2ASM_AST_ADDRESSING_RODATA_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class RODATA: public cdk::basic_node {
  public:
    RODATA(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_RODATA(this, level);
    }
  };

} // pf2asm

#endif
