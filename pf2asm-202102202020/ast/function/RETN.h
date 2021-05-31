#ifndef __PF2ASM_AST_FUNCTION_RETN_H__
#define __PF2ASM_AST_FUNCTION_RETN_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class RETN: public cdk::basic_node {
    int _value;

  public:
    RETN(int lineno, int value) :
        cdk::basic_node(lineno), _value(value) {
    }
    int value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_RETN(this, level);
    }
  };

} // pf2asm

#endif
