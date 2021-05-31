#ifndef __PF2ASM_AST_LOADSTORE_LDINT_H__
#define __PF2ASM_AST_LOADSTORE_LDINT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LDINT: public cdk::basic_node {
  public:
    LDINT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LDINT(this, level);
    }
  };

} // pf2asm

#endif
