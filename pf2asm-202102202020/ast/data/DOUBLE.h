#ifndef __PF2ASM_AST_DATA_DOUBLE_H__
#define __PF2ASM_AST_DATA_DOUBLE_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class DOUBLE: public cdk::basic_node {
    double _value;

  public:
    DOUBLE(int lineno, double value) :
        cdk::basic_node(lineno), _value(value) {
    }
    double value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_DOUBLE(this, level);
    }
  };

} // pf2asm

#endif
