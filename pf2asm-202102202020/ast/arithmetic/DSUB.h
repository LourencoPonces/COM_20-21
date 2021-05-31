#ifndef __PF2ASM_AST_ARITHMETIC_DSUB_H__
#define __PF2ASM_AST_ARITHMETIC_DSUB_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DSUB: public cdk::basic_node {
  public:
    DSUB(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DSUB(this, level);
    }
  };

} // pf2asm

#endif
