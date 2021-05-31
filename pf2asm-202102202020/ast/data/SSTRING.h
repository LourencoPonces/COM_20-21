#ifndef __PF2ASM_AST_DATA_SSTRING_H__
#define __PF2ASM_AST_DATA_SSTRING_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class SSTRING: public cdk::basic_node {
    std::string _value;

  public:
    SSTRING(int lineno, const std::string &value) :
        cdk::basic_node(lineno), _value(value) {
    }
    const std::string & value() const {
      return _value;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_SSTRING(this, level);
    }
  };

} // pf2asm

#endif
