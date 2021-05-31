#ifndef __PF2ASM_AST_I2D_H__
#define __PF2ASM_AST_I2D_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class I2D: public cdk::basic_node {
  public:
    I2D(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_I2D(this, level);
    }
  };

} // pf2asm

#endif
