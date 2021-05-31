#ifndef __PF2ASM_AST_DATA_FLOAT_H__
#define __PF2ASM_AST_DATA_FLOAT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class FLOAT: public cdk::basic_node {
    double _value;

  public:
    FLOAT(int lineno, float value) :
        cdk::basic_node(lineno), _value(value) {
    }
    double value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_FLOAT(this, level);
    }
  };

} // pf2asm

#endif
