#ifndef __PF2ASM_AST_RELATIONAL_LE_H__
#define __PF2ASM_AST_RELATIONAL_LE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LE: public cdk::basic_node {
  public:
    LE(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LE(this, level);
    }
  };

} // pf2asm

#endif
