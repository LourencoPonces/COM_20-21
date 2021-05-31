#ifndef __PF2ASM_AST_LOADSTORE_LDBYTE_H__
#define __PF2ASM_AST_LOADSTORE_LDBYTE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LDBYTE: public cdk::basic_node {
  public:
    LDBYTE(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LDBYTE(this, level);
    }
  };

} // pf2asm

#endif
