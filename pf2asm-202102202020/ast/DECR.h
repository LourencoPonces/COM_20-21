#ifndef __PF2ASM_AST_DECR_H__
#define __PF2ASM_AST_DECR_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DECR: public cdk::basic_node {
    int _value;

  public:
    DECR(int lineno, int value) :
        cdk::basic_node(lineno), _value(value) {
    }
    int value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DECR(this, level);
    }
  };

} // pf2asm

#endif
