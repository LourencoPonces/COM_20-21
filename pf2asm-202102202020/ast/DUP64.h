#ifndef __PF2ASM_AST_DUP64_H__
#define __PF2ASM_AST_DUP64_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DUP64: public cdk::basic_node {
  public:
    DUP64(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DUP64(this, level);
    }
  };

} // pf2asm

#endif
