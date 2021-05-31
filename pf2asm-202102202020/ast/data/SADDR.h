#ifndef __PF2ASM_AST_DATA_SADDR_H__
#define __PF2ASM_AST_DATA_SADDR_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SADDR: public cdk::basic_node {
    std::string _value;

  public:
    SADDR(int lineno, const std::string &value) :
        cdk::basic_node(lineno), _value(value) {
    }
    const std::string & value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SADDR(this, level);
    }
  };

} // pf2asm

#endif
