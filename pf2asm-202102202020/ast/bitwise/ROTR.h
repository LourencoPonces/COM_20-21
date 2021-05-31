#ifndef __PF2ASM_AST_BITWISE_ROTR_H__
#define __PF2ASM_AST_BITWISE_ROTR_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class ROTR: public cdk::basic_node {
  public:
    ROTR(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_ROTR(this, level);
    }
  };

} // pf2asm

#endif
