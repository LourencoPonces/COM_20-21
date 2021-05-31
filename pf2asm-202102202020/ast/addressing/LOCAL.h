#ifndef __PF2ASM_AST_ADDRESSING_LOCAL_H__
#define __PF2ASM_AST_ADDRESSING_LOCAL_H__

#include <cdk/ast/basic_node.h>

namespace pf2asm {

  class LOCAL: public cdk::basic_node {
    int _offset;

  public:
    LOCAL(int lineno, int offset) :
        cdk::basic_node(lineno), _offset(offset) {
    }
    int offset() const {
      return _offset;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_LOCAL(this, level);
    }
  };

} // pf2asm

#endif
