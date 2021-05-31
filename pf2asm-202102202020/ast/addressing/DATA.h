#ifndef __PF2ASM_AST_ADDRESSING_DATA_H__
#define __PF2ASM_AST_ADDRESSING_DATA_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DATA: public cdk::basic_node {
  public:
    DATA(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DATA(this, level);
    }
  };

} // pf2asm

#endif
