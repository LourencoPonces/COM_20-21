#ifndef __PF2ASM_AST_ADDRESSING_LOCA_H__
#define __PF2ASM_AST_ADDRESSING_LOCA_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LOCA: public cdk::basic_node {
    int _offset;

  public:
    LOCA(int lineno, int offset) :
        cdk::basic_node(lineno), _offset(offset) {
    }
    int offset() const {
      return _offset;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LOCA(this, level);
    }
  };

} // pf2asm

#endif
