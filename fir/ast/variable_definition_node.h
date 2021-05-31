#ifndef __FIR_AST_VARIABLE_DEFINITION_H__
#define __FIR_AST_VARIABLE_DEFINITION_H__

#include <cdk/ast/typed_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/types/basic_type.h>

namespace fir {

  class variable_definition_node: public cdk::typed_node {
    //! qualifier = 0 : omision -> private (Default value)
    //! qualifier = 1 : *       -> public 
    //! qualifier = 2 : ?       -> defined in other modules 
    int _qualifier;
    std::string _identifier;
    cdk::expression_node *_initializer;

  public:
    variable_definition_node(int lineno, std::shared_ptr<cdk::basic_type> varType, int qualifier, const std::string &identifier,
                              cdk::expression_node *initializer) :
        cdk::typed_node(lineno), _qualifier(qualifier), _identifier(identifier), _initializer(initializer) {
      type(varType);
    }

  public:
    int qualifier() {
      return _qualifier;
    }
    const std::string& identifier() const {
      return _identifier;
    }
    cdk::expression_node* initializer() {
      return _initializer;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_definition_node(this, level);
    }

  };

} // fir

#endif
