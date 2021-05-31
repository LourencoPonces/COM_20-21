#ifndef __PF2ASM_AST_RELATIONAL_EQ_H__
#define __PF2ASM_AST_RELATIONAL_EQ_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class EQ: public cdk::basic_node {
  public:
    EQ(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_EQ(this, level);
    }
  };

} // pf2asm

#endif
