#ifndef __GR8_AST_SWEEP_H__
#define __GR8_AST_SWEEP_H__

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>

namespace gr8 {

  class sweep_node: public cdk::basic_node {
  protected:
    cdk::lvalue_node *_lvalue;
    cdk::expression_node *_begin;
    cdk::expression_node *_end;
    cdk::expression_node *_step;
    cdk::basic_node *_instruction;

  public:
    sweep_node(int lineno, cdk::lvalue_node *lvalue, cdk::expression_node *begin, cdk::expression_node *end,
               cdk::expression_node *step, cdk::basic_node *instruction) :
        cdk::basic_node(lineno), _lvalue(lvalue), _begin(begin), _end(end), _step(step), _instruction(instruction) {
    }

  public:
    cdk::lvalue_node *lvalue() {
      return _lvalue;
    }
    cdk::expression_node *begin() {
      return _begin;
    }
    cdk::expression_node *end() {
      return _end;
    }
    cdk::expression_node *step() {
      return _step;
    }
    cdk::basic_node *instruction() {
      return _instruction;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_sweep_node(this, level);
    }

  };

} // gr8

#endif
