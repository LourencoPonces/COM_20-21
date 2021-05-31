#ifndef __PF2ASM_AST_LOADSTORE_LDDOUBLE_H__
#define __PF2ASM_AST_LOADSTORE_LDDOUBLE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LDDOUBLE: public cdk::basic_node {
  public:
    LDDOUBLE(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LDDOUBLE(this, level);
    }
  };

} // pf2asm

#endif
