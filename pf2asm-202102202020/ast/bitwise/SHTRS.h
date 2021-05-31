#ifndef __PF2ASM_AST_BITWISE_SHTRS_H__
#define __PF2ASM_AST_BITWISE_SHTRS_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SHTRS: public cdk::basic_node {
  public:
    SHTRS(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SHTRS(this, level);
    }
  };

} // pf2asm

#endif
