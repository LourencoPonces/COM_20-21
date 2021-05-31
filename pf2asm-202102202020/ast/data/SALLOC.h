#ifndef __PF2ASM_AST_DATA_SALLOC_H__
#define __PF2ASM_AST_DATA_SALLOC_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SALLOC: public cdk::basic_node {
    int _value;

  public:
    SALLOC(int lineno, int value) :
        cdk::basic_node(lineno), _value(value) {
    }
    int value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SALLOC(this, level);
    }
  };

} // pf2asm

#endif
