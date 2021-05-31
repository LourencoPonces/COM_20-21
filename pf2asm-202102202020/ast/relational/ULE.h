#ifndef __PF2ASM_AST_RELATIONAL_ULE_H__
#define __PF2ASM_AST_RELATIONAL_ULE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class ULE: public cdk::basic_node {
  public:
    ULE(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_ULE(this, level);
    }
  };

} // pf2asm

#endif
