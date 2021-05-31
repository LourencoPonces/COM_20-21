#ifndef __PF2ASM_AST_SWAP64_H__
#define __PF2ASM_AST_SWAP64_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SWAP64: public cdk::basic_node {
  public:
    SWAP64(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SWAP64(this, level);
    }
  };

} // pf2asm

#endif
