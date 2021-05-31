#ifndef __PF2ASM_TARGETS_POSTFIX_TARGET_H__
#define __PF2ASM_TARGETS_POSTFIX_TARGET_H__

#include <cdk/targets/basic_target.h>
#include <cdk/ast/basic_node.h>
#include "targets/postfix_writer.h"

#include <cdk/emitters/postfix_ix86_emitter.h>

namespace pf2asm {

  class postfix_target: public cdk::basic_target {
    static postfix_target _self;

  private:
    postfix_target() :
        cdk::basic_target("asm") {
    }

  public:
    bool evaluate(std::shared_ptr<cdk::compiler> compiler) {
      // this symbol table will be used to check identifiers
      cdk::symbol_table<std::string> symtab;
      cdk::postfix_ix86_emitter pf(compiler);

      // generate assembly code from the syntax tree
      postfix_writer writer(compiler, symtab, pf);
      compiler->ast()->accept(&writer, 0);

      return true;
    }

  };

} // pf2asm

#endif
