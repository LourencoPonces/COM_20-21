#ifndef __GR8_AST_FUNCTION_DEFINITION_H__
#define __GR8_AST_FUNCTION_DEFINITION_H__

#include <string>
#include <cdk/ast/basic_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "ast/block_node.h"

namespace gr8 {

  /**
   * Class for describing function definitions.
   */
  class function_definition_node: public cdk::basic_node {
    int _qualifier;
    basic_type *_type;
    std::string _identifier;
    cdk::sequence_node *_arguments;
    gr8::block_node *_block;

  public:
    function_definition_node(int lineno, int qualifier, const std::string &identifier, cdk::sequence_node *arguments,
                             gr8::block_node *block) :
        cdk::basic_node(lineno), _qualifier(qualifier), _type(new basic_type(0, basic_type::TYPE_VOID)), _identifier(identifier), _arguments(
            arguments), _block(block) {
    }

    function_definition_node(int lineno, int qualifier, basic_type *type, const std::string &identifier,
                             cdk::sequence_node *arguments, gr8::block_node *block) :
        cdk::basic_node(lineno), _qualifier(qualifier), _type(type), _identifier(identifier), _arguments(arguments), _block(block) {
    }

  public:
    int qualifier() {
      return _qualifier;
    }
    basic_type *type() {
      return _type;
    }
    const std::string &identifier() const {
      return _identifier;
    }
    cdk::sequence_node *arguments() {
      return _arguments;
    }
    gr8::block_node *block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // gr8

#endif
