#ifndef __FIR_AST_FUNCTION_DEFINITION_H__
#define __FIR_AST_FUNCTION_DEFINITION_H__

#include <string>
#include <cdk/ast/typed_node.h>
#include <cdk/ast/sequence_node.h>
#include "ast/body_node.h"
#include <cdk/types/basic_type.h>

namespace fir {

  //!
  //! Class for describing function definitions.
  //! 
  //! declaration: type qualifier id '(' args ')' body
  //!            {
  //!              $$ = new og::function_definition(LINE, $1, $2, $3, $5, $8);
  //!            }
  //!
  //! declaration: type qualifier id '(' args ')' -> default_return_value body
  //!            {
  //!              $$ = new og::function_definition(LINE, $1, $2, $3, $5, $8, $9);
  //!            }
  //!
  class function_definition_node: public cdk::typed_node {
    //! qualifier = 0 : omision -> private (Default value)
    //! qualifier = 1 : *       -> public 
    //! qualifier = 2 : ?       -> defined in other modules 
    int _qualifier;
    std::string _identifier;
    cdk::sequence_node *_arguments;
    cdk::basic_type *_default_return_value;
    fir::body_node *_body;

  public:
    //!
    //! Constructor for a function definition without default return value.
    //! The function is automatically declared as a void function.
    //!
    function_definition_node(int lineno, int qualifier, const std::string &identifier, cdk::sequence_node *arguments,
                             fir::body_node *body) :
        cdk::typed_node(lineno), _qualifier(qualifier), _identifier(identifier), _arguments(arguments), _body(body) {
      type(cdk::primitive_type::create(0, cdk::TYPE_VOID));
    }

    //!
    //! Constructor for a function definition with default return value.
    //!
    function_definition_node(int lineno, int qualifier, std::shared_ptr<cdk::basic_type> funType, const std::string &identifier,
                             cdk::sequence_node *arguments, cdk::basic_type *default_return_value, fir::body_node *body) :
        cdk::typed_node(lineno), _qualifier(qualifier), _identifier(identifier), _arguments(arguments), _default_return_value(default_return_value), _body(body) {
      type(funType);
    }

  public:
    int qualifier() {
      return _qualifier;
    }
    const std::string& identifier() const {
      return _identifier;
    }
    cdk::sequence_node* arguments() {
      return _arguments;
    }
    cdk::typed_node* argument(size_t ax) {
      return dynamic_cast<cdk::typed_node*>(_arguments->node(ax));
    }
    cdk::basic_type* default_return_value() {
      return _default_return_value;
    }
    fir::body_node* body() {
      return _body;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // fir

#endif
