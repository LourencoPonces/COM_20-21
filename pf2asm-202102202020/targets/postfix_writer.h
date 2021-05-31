#ifndef __PF2ASM_TARGETS_POSTFIX_WRITER_H__
#define __PF2ASM_TARGETS_POSTFIX_WRITER_H__

#include "targets/basic_ast_visitor.h"

#include <sstream>
#include <cdk/emitters/basic_postfix_emitter.h>

/**
 * Traverse syntax tree and generate the corresponding PF code.
 * Note that no attempt is made to validate symbols (the assembly
 * parser -- nasm, yasm, etc. -- will do that).
 */

namespace pf2asm {

  class postfix_writer: public basic_ast_visitor {
    cdk::symbol_table<std::string> &_symtab; // not used

    // code generation
    cdk::basic_postfix_emitter &_pf;

    // counter for automatic labels
    int _lbl;

    // current framepointer offset (0 means no vars defined)
    int _offset;

    // semantic analysis errors
    bool _errors;

  public:
    postfix_writer(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<std::string> &symtab, cdk::basic_postfix_emitter &pf) :
        basic_ast_visitor(compiler), _symtab(symtab), _pf(pf), _lbl(0), _offset(0), _errors(false) {
    }

  public:
    ~postfix_writer() {
      os().flush();
    }

  private:
    std::string mklbl(int lbl) {
      std::ostringstream oss;
      if (lbl < 0)
        oss << ".L" << -lbl;
      else
        oss << "_L" << lbl;
      return oss.str();
    }

    void error(int lineno, std::string s) {
      std::cerr << "error: " << lineno << ": " << s << std::endl;
    }

  public:
    // do not edit these lines
#define __IN_VISITOR_HEADER__
#include "ast/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
    // do not edit these lines: end

  };

} // pf2asm

#endif
