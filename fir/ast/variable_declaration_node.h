#ifndef __FIR_AST_VARIABLE_DECLARATION_H__
#define __FIR_AST_VARIABLE_DECLARATION_H__

#include <cdk/ast/typed_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/types/basic_type.h>

namespace fir {

  class variable_declaration_node: public cdk::typed_node {
    //! qualifier = 0 : omision -> private (Default value)
    //! qualifier = 1 : *       -> public 
    //! qualifier = 2 : ?       -> defined in other modules 
    int _qualifier;
    std::string _identifier;

  public:
    variable_declaration_node(int lineno, int qualifier, std::shared_ptr<cdk::basic_type> varType, const std::string &identifier) :
        cdk::typed_node(lineno), _qualifier(qualifier), _identifier(identifier) {
      type(varType);
    }

  public:
    int qualifier() {
      return _qualifier;
    }
    const std::string& identifier() const {
      return _identifier;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_declaration_node(this, level);
    }

  };

} // fir

#endif
