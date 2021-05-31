#ifndef __PF2ASM_AST_BITWISE_SHTL_H__
#define __PF2ASM_AST_BITWISE_SHTL_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SHTL: public cdk::basic_node {
  public:
    SHTL(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SHTL(this, level);
    }
  };

} // pf2asm

#endif
