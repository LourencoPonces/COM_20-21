#ifndef __PF2ASM_AST_DATA_SBYTE_H__
#define __PF2ASM_AST_DATA_SBYTE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SBYTE: public cdk::basic_node {
    char _value;

  public:
    SBYTE(int lineno, char value) :
        cdk::basic_node(lineno), _value(value) {
    }
    char value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SBYTE(this, level);
    }
  };

} // pf2asm

#endif
