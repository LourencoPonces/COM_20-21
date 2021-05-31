#ifndef __PF2ASM_AST_DATA_SFLOAT_H__
#define __PF2ASM_AST_DATA_SFLOAT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SFLOAT: public cdk::basic_node {
    float _value;

  public:
    SFLOAT(int lineno, float value) :
        cdk::basic_node(lineno), _value(value) {
    }
    float value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SFLOAT(this, level);
    }
  };

} // pf2asm

#endif
