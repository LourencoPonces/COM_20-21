#ifndef __PF2ASM_AST_ADDRESSING_TEXT_H__
#define __PF2ASM_AST_ADDRESSING_TEXT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class TEXT: public cdk::basic_node {
  public:
    TEXT(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_TEXT(this, level);
    }
  };

} // pf2asm

#endif
