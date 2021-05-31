#ifndef __FIR_AST_FUNCTION_DECLARATION_H__
#define __FIR_AST_FUNCTION_DECLARATION_H__

#include <string>
#include <cdk/ast/typed_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>

namespace fir {

  //!
  //! Class for describing function declarations.
  //! 
  //! declaration: void qualifier id '(' args ')'
  //!            { 
  //!              new fir::function::Declaration(LINE, $2, $3, $5);
  //!            }
  //!
  //! declaration: type qualifier id '(' args ')'
  //!            { 
  //!              new fir::function::Declaration(LINE, $1, $2, $3, $5);
  //!            }
  //!
  
  class function_declaration_node: public cdk::typed_node {
    //! qualifier = 0 : omision -> private (Default value)
    //! qualifier = 1 : *       -> public 
    //! qualifier = 2 : ?       -> defined in other modules 
    int _qualifier;
    std::string _identifier;
    cdk::sequence_node *_arguments;

  public:
    //!
    //! The function is automatically declared as a void function.
    //!
    function_declaration_node(int lineno, int qualifier, const std::string &identifier, cdk::sequence_node *arguments) :
        cdk::typed_node(lineno), _qualifier(qualifier), _identifier(identifier), _arguments(arguments) {
      type(cdk::primitive_type::create(0, cdk::TYPE_VOID));
    }

    //!
    //! Constructor for a function declaration with a type that it is not void.
    //!
    function_declaration_node(int lineno, std::shared_ptr<cdk::basic_type> funType, int qualifier,  const std::string &identifier,
                              cdk::sequence_node *arguments) :
        cdk::typed_node(lineno), _qualifier(qualifier), _identifier(identifier), _arguments(arguments) {
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
   
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_declaration_node(this, level);
    }

  };

} // fir

#endif
