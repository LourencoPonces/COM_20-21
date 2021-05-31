#ifndef __PF2ASM_AST_DATA_SDOUBLE_H__
#define __PF2ASM_AST_DATA_SDOUBLE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SDOUBLE: public cdk::basic_node {
    double _value;

  public:
    SDOUBLE(int lineno, double value) :
        cdk::basic_node(lineno), _value(value) {
    }
    double value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SDOUBLE(this, level);
    }
  };

} // pf2asm

#endif
