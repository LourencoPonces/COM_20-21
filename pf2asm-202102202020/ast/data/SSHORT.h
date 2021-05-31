#ifndef __PF2ASM_AST_DATA_SSHORT_H__
#define __PF2ASM_AST_DATA_SSHORT_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SSHORT: public cdk::basic_node {
    short _value;

  public:
    SSHORT(int lineno, int value) :
        cdk::basic_node(lineno), _value(value) {
    }
    short value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SSHORT(this, level);
    }
  };

} // pf2asm

#endif
