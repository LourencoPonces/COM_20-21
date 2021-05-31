#ifndef __PF2ASM_FACTORY_H__
#define __PF2ASM_FACTORY_H__

#include <memory>
#include <cdk/yy_factory.h>
#include "pf2asm_scanner.h"

namespace pf2asm {

  /**
   * This class implements the compiler factory for the Compact compiler.
   */
  class factory: public cdk::yy_factory<pf2asm_scanner> {
    /**
     * This object is automatically registered by the constructor in the
     * superclass' language registry.
     */
    static factory _self;

  protected:
    /**
     * @param language name of the language handled by this factory (see .cpp file)
     */
    factory(const std::string &language = "pf2asm") :
        cdk::yy_factory<pf2asm_scanner>(language) {
    }

  };

} // pf2asm

#endif
