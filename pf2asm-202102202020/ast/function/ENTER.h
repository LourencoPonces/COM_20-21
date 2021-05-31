#ifndef __PF2ASM_AST_FUNCTION_ENTER_H__
#define __PF2ASM_AST_FUNCTION_ENTER_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class ENTER: public cdk::basic_node {
    int _value;

  public:
    ENTER(int lineno, int value) :
        cdk::basic_node(lineno), _value(value) {
    }
    int value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_ENTER(this, level);
    }
  };

} // pf2asm

#endif
