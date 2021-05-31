#ifndef __GR8_TARGET_SYMBOL_H__
#define __GR8_TARGET_SYMBOL_H__

#include <string>
#include <cdk/basic_type.h>

namespace gr8 {

  class symbol {

    std::string _name;
    int _value;

    bool _constant;
    int _qualifier;
    basic_type *_type;
    bool _initialized;
    int _offset = 0; // 0 (zero) means global variable/function
    bool _function; // false for variables
    bool _forward = false;

  public:
    symbol(bool constant, int qualifier, basic_type *type, const std::string &name, bool initialized, bool function, bool forward =
               false) :
        _name(name), _value(0), _constant(constant), _qualifier(qualifier), _type(type), _initialized(initialized), _function(
            function), _forward(forward) {
    }

    ~symbol() {
    }

    const std::string &name() const {
      return _name;
    }
    int value() const {
      return _value;
    }
    int value(int v) {
      return _value = v;
    }

    bool constant() const {
      return _constant;
    }
    int qualifier() const {
      return _qualifier;
    }
    basic_type *type() {
      return _type;
    }
    const std::string &identifier() const {
      return name();
    }
    bool initialized() const {
      return _initialized;
    }
    int offset() const {
      return _offset;
    }
    void set_offset(int offset) {
      _offset = offset;
    }
    bool isFunction() const {
      return _function;
    }

    bool global() const {
      return _offset == 0;
    }
    bool isVariable() const {
      return !_function;
    }

    bool forward() const {
      return _forward;
    }

  };

} // gr8

#endif
