#ifndef __PF2ASM_AST_LOADSTORE_STBYTE_H__
#define __PF2ASM_AST_LOADSTORE_STBYTE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class STBYTE: public cdk::basic_node {
  public:
    STBYTE(int lineno) :
        cdk::basic_node(lineno) {
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_STBYTE(this, level);
    }
  };

} // pf2asm

#endif
