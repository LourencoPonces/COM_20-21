#ifndef __PF2ASM_AST_JUMPS_JNZ_H__
#define __PF2ASM_AST_JUMPS_JNZ_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class JNZ: public cdk::basic_node {
    std::string _label;

  public:
    JNZ(int lineno, std::string &label) :
        cdk::basic_node(lineno), _label(label) {
    }
    const std::string &label() const {
      return _label;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_JNZ(this, level);
    }
  };

} // pf2asm

#endif
