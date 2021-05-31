#ifndef __PF2ASM_AST_BITWISE_SHTRU_H__
#define __PF2ASM_AST_BITWISE_SHTRU_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SHTRU: public cdk::basic_node {
  public:
    SHTRU(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SHTRU(this, level);
    }
  };

} // pf2asm

#endif
