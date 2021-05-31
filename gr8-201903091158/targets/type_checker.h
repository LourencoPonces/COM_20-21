#ifndef __GR8_TARGET_TYPE_CHECKER_H__
#define __GR8_TARGET_TYPE_CHECKER_H__

#include "targets/basic_ast_visitor.h"

#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <cdk/basic_type.h>
#include <cdk/symbol_table.h>
#include "targets/symbol.h"

namespace gr8 {

  class type_checker: public virtual basic_ast_visitor {
    cdk::symbol_table<gr8::symbol> &_symtab;
    std::shared_ptr<gr8::symbol> _function;
    basic_ast_visitor *_parent;

  public:
    type_checker(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<gr8::symbol> &symtab, std::shared_ptr<gr8::symbol> func,
                 basic_ast_visitor *parent) :
        basic_ast_visitor(compiler), _symtab(symtab), _function(func), _parent(parent) {
    }

  public:
    ~type_checker();

  protected:
    void do_ArithmeticExpression(cdk::binary_expression_node * const node, int lvl) {
      throw 42;
    }
    void do_IntOnlyExpression(cdk::binary_expression_node * const node, int lvl);
    void do_PIDExpression(cdk::binary_expression_node * const node, int lvl);
    void do_IDExpression(cdk::binary_expression_node * const node, int lvl);

  protected:
    void do_ScalarLogicalExpression(cdk::binary_expression_node * const node, int lvl);
    void do_BooleanLogicalExpression(cdk::binary_expression_node * const node, int lvl);
    void do_GeneralLogicalExpression(cdk::binary_expression_node * const node, int lvl);

  public:
    // do not edit these lines
#define __IN_VISITOR_HEADER__
#include "ast/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
    // do not edit these lines: end

  };

//---------------------------------------------------------------------------
//     HELPER MACRO FOR TYPE CHECKING
//---------------------------------------------------------------------------

#define CHECK_TYPES(compiler, symtab, function, node) { \
    try { \
      gr8::type_checker checker(compiler, symtab, function, this); \
      (node)->accept(&checker, 0); \
    } \
    catch (const std::string &problem) { \
      std::cerr << (node)->lineno() << ": " << problem << std::endl; \
      return; \
    } \
  }

#define ASSERT_SAFE CHECK_TYPES(_compiler, _symtab, _function, node)

} // gr8

#endif
