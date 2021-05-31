#ifndef __PF2ASM_AST_ADDRESSING_GLOBAL_H__
#define __PF2ASM_AST_ADDRESSING_GLOBAL_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class GLOBAL: public cdk::basic_node {
    std::string _label;
    std::string _type;

  public:
    GLOBAL(int lineno, std::string &label, std::string &type) :
        cdk::basic_node(lineno), _label(label), _type(type) {
    }
    const std::string &label() const {
      return _label;
    }
    const std::string &type() const {
      return _type;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_GLOBAL(this, level);
    }
  };

} // pf2asm

#endif
