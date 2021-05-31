#ifndef __PF2ASM_AST_LOADSTORE_LDSHORT_H__
#define __PF2ASM_AST_LOADSTORE_LDSHORT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LDSHORT: public cdk::basic_node {
  public:
    LDSHORT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LDSHORT(this, level);
    }
  };

} // pf2asm

#endif
