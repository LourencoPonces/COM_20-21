#ifndef __PF2ASM_AST_LOADSTORE_STINT_H__
#define __PF2ASM_AST_LOADSTORE_STINT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class STINT: public cdk::basic_node {
  public:
    STINT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_STINT(this, level);
    }
  };

} // pf2asm

#endif
