#ifndef __PF2ASM_AST_BITWISE_NOT_H__
#define __PF2ASM_AST_BITWISE_NOT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class NOT: public cdk::basic_node {
  public:
    NOT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_NOT(this, level);
    }
  };

} // pf2asm

#endif
