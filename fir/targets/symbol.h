#ifndef __FIR_TARGETS_SYMBOL_H__
#define __FIR_TARGETS_SYMBOL_H__

#include <string>
#include <memory>
#include <cdk/types/basic_type.h>

namespace fir {

  class symbol {

    std::shared_ptr<cdk::basic_type> _type; // void, int, float, string, pointer
    int _qualifier; // public (*), require (?), private (none)
    std::string _id; // identifier
    bool _initialized; // initialized?
    bool _function; // false for variables
    std::vector<std::shared_ptr<cdk::basic_type>> _arguments_types;

    int _offset = 0; // 0 (zero) means global variable/function
    
    // int _value;


  public:
    symbol(std::shared_ptr<cdk::basic_type> type, 
           int qualifier, 
           const std::string &id, 
           bool initialized,
           bool function) :
         _type(type), _qualifier(qualifier), _id(id), _initialized(initialized), _function(function)/*,_value(0) */{
    }

    ~symbol() {
    }

    std::shared_ptr<cdk::basic_type> type() const {
      return _type;
    }
    void set_type(std::shared_ptr<cdk::basic_type> new_type) {
      _type = new_type;
    }
    bool is_typed(cdk::typename_type name) const {
      return _type->name() == name;
    }
    const std::string& identifier() const {
      return _id;
    }
    bool initialized() const {
      return _initialized;
    }
    int qualifier() const {
      return _qualifier;
    }
    bool function() const {
      return _function;
    }
    int offset() const {
      return _offset;
    }
    void set_offset(int offset) {
      _offset = offset;
    }
    // int value() const {
    //   return _value;
    // }
    // int value(int new_value) {
    //   return _value = new_value;
    // }
    std::vector<std::shared_ptr<cdk::basic_type>> arguments_types() const {
      return _arguments_types;
    }
    void set_arguments_types(const std::vector<std::shared_ptr<cdk::basic_type>> &types) {
      _arguments_types = types;
    }
    size_t number_of_arguments() const {
      return _arguments_types.size();
    }

  };

} // fir

#endif
