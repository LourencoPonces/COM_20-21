#ifndef __PF2ASM_AST_ARITHMETIC_DADD_H__
#define __PF2ASM_AST_ARITHMETIC_DADD_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DADD: public cdk::basic_node {
  public:
    DADD(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DADD(this, level);
    }
  };

} // pf2asm

#endif
