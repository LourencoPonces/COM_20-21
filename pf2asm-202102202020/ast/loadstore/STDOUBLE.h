#ifndef __PF2ASM_AST_LOADSTORE_STDOUBLE_H__
#define __PF2ASM_AST_LOADSTORE_STDOUBLE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class STDOUBLE: public cdk::basic_node {
  public:
    STDOUBLE(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_STDOUBLE(this, level);
    }
  };

} // pf2asm

#endif
