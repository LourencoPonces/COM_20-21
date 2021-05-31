#ifndef __PF2ASM_AST_SWAP32_H__
#define __PF2ASM_AST_SWAP32_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SWAP32: public cdk::basic_node {
  public:
    SWAP32(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SWAP32(this, level);
    }
  };

} // pf2asm

#endif
