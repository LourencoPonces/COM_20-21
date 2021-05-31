#ifndef __PF2ASM_AST_LOADSTORE_STSHORT_H__
#define __PF2ASM_AST_LOADSTORE_STSHORT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class STSHORT: public cdk::basic_node {
  public:
    STSHORT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_STSHORT(this, level);
    }
  };

} // pf2asm

#endif
