#ifndef __PF2ASM_AST_RELATIONAL_DCMP_H__
#define __PF2ASM_AST_RELATIONAL_DCMP_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DCMP: public cdk::basic_node {
  public:
    DCMP(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DCMP(this, level);
    }
  };

} // pf2asm

#endif
