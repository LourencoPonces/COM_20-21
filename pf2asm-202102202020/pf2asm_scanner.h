#ifndef __PF2ASM_PF2ASM_SCANNER_H__
#define __PF2ASM_PF2ASM_SCANNER_H__

#undef yyFlexLexer
#define yyFlexLexer pf2asm_scanner_FlexLexer
#include <FlexLexer.h>

typedef pf2asm_scanner_FlexLexer pf2asm_scanner;

#endif
