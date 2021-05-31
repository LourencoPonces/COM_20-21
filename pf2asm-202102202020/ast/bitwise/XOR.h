#ifndef __PF2ASM_AST_BITWISE_XOR_H__
#define __PF2ASM_AST_BITWISE_XOR_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class XOR: public cdk::basic_node {
  public:
    XOR(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_XOR(this, level);
    }
  };

} // pf2asm

#endif
