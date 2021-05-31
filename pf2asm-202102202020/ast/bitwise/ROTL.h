#ifndef __PF2ASM_AST_BITWISE_ROTL_H__
#define __PF2ASM_AST_BITWISE_ROTL_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class ROTL: public cdk::basic_node {
  public:
    ROTL(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_ROTL(this, level);
    }
  };

} // pf2asm

#endif
