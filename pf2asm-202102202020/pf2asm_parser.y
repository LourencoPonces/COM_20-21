%{
// $Id: $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include "ast/all.h"
#define LINE                  compiler->scanner()->lineno()
#define yylex()               compiler->scanner()->scan()
#define yyerror(compiler, s)  compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                  i;             /* integer number */
  double               d;             /* real number */
  std::string         *s;             /* symbol name or string literal */
  cdk::basic_node     *node;          /* node pointer */
  cdk::sequence_node  *sequence;      /* node pointer */
}

%token tBSS tDATA tRODATA tTEXT
%token tSBYTE tSSHORT tSINT tSFLOAT tSDOUBLE tSSTRING tSALLOC tSADDR
%token tALIGN tLABEL tEXTERN tGLOBAL
%token tADDR tADDRA tADDRV tLOCAL tLOCA tLOCV
%token tLDBYTE tLDSHORT tLDINT tLDFLOAT tLDDOUBLE
%token tSTBYTE tSTSHORT tSTINT tSTFLOAT tSTDOUBLE
%token tSP tALLOC tDUP32 tDUP64 tSWAP32 tSWAP64 tINT tFLOAT tDOUBLE
%token tNEG tADD tSUB tMUL tDIV tUDIV tMOD tUMOD
%token tDNEG tDADD tDSUB tDMUL tDDIV
%token tINCR tDECR
%token tD2F tF2D tD2I tI2D
%token tEQ tNE
%token tGT tGE tLE tLT
%token tUGT tUGE tULE tULT
%token tDCMP
%token tNOT tAND tOR tXOR
%token tROTL tROTR tSHTL tSHTRU tSHTRS
%token tENTER tSTART tLEAVE tRET tRETN tCALL tTRASH
%token tSTFVAL32 tSTFVAL64 tLDFVAL32 tLDFVAL64
%token tJMP tLEAP tBRANCH
%token tJZ tJNZ
%token tJEQ tJNE
%token tJGT tJGE tJLE tJLT
%token tJUGT tJUGE tJULE tJULT
%token tNIL tNOP
%token T_AND T_OR T_NE T_LE T_GE

%token<i> T_LIT_INT
%token<d> T_LIT_REAL
%token<s> T_LIT_STRING T_ID

%type<node> instruction data function addressing loadstore jumps
%type<node> bitwise arithmetic relational
%type<sequence> file instructions  
%type<s> label type
%type<i> integer bytes offset

%nonassoc '?'
%nonassoc ':'
%left T_OR
%left T_AND
%left T_NE T_EQ
%left '<' T_LE T_GE '>'
%left '+' '-'
%left '*' '/' '%'
%right T_UMINUS '!'

%%

file	        : /* empty */  { compiler->ast($$ = new cdk::sequence_node(LINE, new cdk::nil_node(LINE))); }
                | instructions { compiler->ast($$ = $1); }
                ;

instructions    : instruction                                { $$ = new cdk::sequence_node(LINE, $1);     }
                | instructions instruction                   { $$ = new cdk::sequence_node(LINE, $2, $1); }
                ;

instruction     : tNOP              { $$ = new pf2asm::NOP(LINE); }
                | tINCR integer     { $$ = new pf2asm::INCR(LINE, $2); }
                | tDECR integer     { $$ = new pf2asm::DECR(LINE, $2); }
                | tALLOC            { $$ = new pf2asm::ALLOC(LINE); }
                | tTRASH bytes      { $$ = new pf2asm::TRASH(LINE, $2); }
                | tDUP32            { $$ = new pf2asm::DUP32(LINE); }
                | tDUP64            { $$ = new pf2asm::DUP64(LINE); }
                | tSWAP32           { $$ = new pf2asm::SWAP32(LINE); }
                | tSWAP64           { $$ = new pf2asm::SWAP64(LINE); }
                | tSP               { $$ = new pf2asm::SP(LINE); }
                | tI2D              { $$ = new pf2asm::I2D(LINE); }
                | tF2D              { $$ = new pf2asm::F2D(LINE); }
                | tD2I              { $$ = new pf2asm::D2I(LINE); }
                | tD2F              { $$ = new pf2asm::D2F(LINE); }
                | tNIL              { $$ = new pf2asm::NIL(LINE); }
                | data              { $$ = $1; }
                | function          { $$ = $1; }
                | addressing        { $$ = $1; }
                | loadstore         { $$ = $1; }
                | bitwise           { $$ = $1; }
                | arithmetic        { $$ = $1; }
                | relational        { $$ = $1; }
                | jumps             { $$ = $1; }
                ;

bytes           : integer           { $$ = $1; };

data            : tSINT    integer      { $$ = new pf2asm::SINT   (LINE, $2); }
                | tSSHORT  integer      { $$ = new pf2asm::SSHORT (LINE, $2); }
                | tSSTRING T_LIT_STRING { $$ = new pf2asm::SSTRING(LINE, *$2); delete $2; }
                | tSBYTE   T_LIT_STRING { $$ = new pf2asm::SBYTE  (LINE, (*$2)[0]); delete $2; }
                | tSADDR   label        { $$ = new pf2asm::SADDR  (LINE, *$2); delete $2; }
                | tSALLOC  integer      { $$ = new pf2asm::SALLOC (LINE, $2); }
                | tSFLOAT  T_LIT_REAL   { $$ = new pf2asm::SFLOAT (LINE, $2); }
                | tSDOUBLE T_LIT_REAL   { $$ = new pf2asm::SDOUBLE(LINE, $2); }
                | tINT     integer      { $$ = new pf2asm::INT    (LINE, $2); }
                | tFLOAT   T_LIT_REAL   { $$ = new pf2asm::FLOAT  (LINE, $2); }
                | tDOUBLE  T_LIT_REAL   { $$ = new pf2asm::DOUBLE (LINE, $2); }
                ;

addressing      : tTEXT             { $$ = new pf2asm::TEXT   (LINE); }
                | tRODATA           { $$ = new pf2asm::RODATA (LINE); }
                | tDATA             { $$ = new pf2asm::DATA   (LINE); }
                | tBSS              { $$ = new pf2asm::BSS    (LINE); }
                | tALIGN            { $$ = new pf2asm::ALIGN  (LINE); }
                | tLOCAL  offset    { $$ = new pf2asm::LOCAL  (LINE, $2); }
                | tLOCV   offset    { $$ = new pf2asm::LOCV   (LINE, $2); }
                | tLOCA   offset    { $$ = new pf2asm::LOCA   (LINE, $2); }
                | tGLOBAL label ',' type  { $$ = new pf2asm::GLOBAL(LINE, *$2, *$4); delete $2; delete $4; }
                | tEXTERN label     { $$ = new pf2asm::EXTERN (LINE, *$2); delete $2; }
                | tLABEL  label     { $$ = new pf2asm::LABEL  (LINE, *$2); delete $2; }
                | tADDR   label     { $$ = new pf2asm::ADDR   (LINE, *$2); delete $2; }
                | tADDRV  label     { $$ = new pf2asm::ADDRV  (LINE, *$2); delete $2; }
                | tADDRA  label     { $$ = new pf2asm::ADDRA  (LINE, *$2); delete $2; }
                ;

offset          : integer         { $$ = $1; };
label           : T_ID            { $$ = $1; };
type            : T_ID            { $$ = $1; };

function        : tENTER bytes   { $$ = new pf2asm::ENTER(LINE, $2); }
                | tSTART         { $$ = new pf2asm::START(LINE);   }
                | tLEAVE         { $$ = new pf2asm::LEAVE(LINE);   }
                | tCALL  label   { $$ = new pf2asm::CALL(LINE, *$2); delete $2; }
                | tRET           { $$ = new pf2asm::RET(LINE);      }
                | tRETN  bytes   { $$ = new pf2asm::RETN(LINE, $2); }
                | tLDFVAL32      { $$ = new pf2asm::LDFVAL32(LINE); }
                | tSTFVAL32      { $$ = new pf2asm::STFVAL32(LINE); }
                | tLDFVAL64      { $$ = new pf2asm::LDFVAL64(LINE); }
                | tSTFVAL64      { $$ = new pf2asm::STFVAL64(LINE); }
                ;

loadstore       : tLDBYTE        { $$ = new pf2asm::LDBYTE(LINE);   }
                | tSTBYTE        { $$ = new pf2asm::STBYTE(LINE);   }
                | tLDSHORT       { $$ = new pf2asm::LDSHORT(LINE);  }
                | tSTSHORT       { $$ = new pf2asm::STSHORT(LINE);  }
                | tLDINT         { $$ = new pf2asm::LDINT(LINE);    }
                | tSTINT         { $$ = new pf2asm::STINT(LINE);    }
                | tLDFLOAT       { $$ = new pf2asm::LDFLOAT(LINE);  }
                | tSTFLOAT       { $$ = new pf2asm::STFLOAT(LINE);  }
                | tLDDOUBLE      { $$ = new pf2asm::LDDOUBLE(LINE); }
                | tSTDOUBLE      { $$ = new pf2asm::STDOUBLE(LINE); }
                ;

arithmetic      : tADD           { $$ = new pf2asm::ADD(LINE);  }
                | tSUB           { $$ = new pf2asm::SUB(LINE);  }
                | tMUL           { $$ = new pf2asm::MUL(LINE);  }
                | tDIV           { $$ = new pf2asm::DIV(LINE);  }
                | tMOD           { $$ = new pf2asm::MOD(LINE);  }
                | tNEG           { $$ = new pf2asm::NEG(LINE);  }
                | tUDIV          { $$ = new pf2asm::UDIV(LINE); }
                | tUMOD          { $$ = new pf2asm::UMOD(LINE); }
                | tDADD          { $$ = new pf2asm::DADD(LINE); }
                | tDSUB          { $$ = new pf2asm::DSUB(LINE); }
                | tDMUL          { $$ = new pf2asm::DMUL(LINE); }
                | tDDIV          { $$ = new pf2asm::DDIV(LINE); }
                | tDNEG          { $$ = new pf2asm::DNEG(LINE); }
                ;
                
bitwise         : tROTL          { $$ = new pf2asm::ROTL(LINE);  }
                | tROTR          { $$ = new pf2asm::ROTR(LINE);  }
                | tSHTL          { $$ = new pf2asm::SHTL(LINE);  }
                | tSHTRU         { $$ = new pf2asm::SHTRU(LINE); }
                | tSHTRS         { $$ = new pf2asm::SHTRS(LINE); }
                | tAND           { $$ = new pf2asm::AND(LINE); }
                | tOR            { $$ = new pf2asm::OR(LINE);  }
                | tXOR           { $$ = new pf2asm::XOR(LINE); }
                | tNOT           { $$ = new pf2asm::NOT(LINE); }
                ;

relational      : tGT            { $$ = new pf2asm::GT(LINE);   }
                | tGE            { $$ = new pf2asm::GE(LINE);   }
                | tLT            { $$ = new pf2asm::LT(LINE);   }
                | tLE            { $$ = new pf2asm::LE(LINE);   }
                | tEQ            { $$ = new pf2asm::EQ(LINE);   }
                | tNE            { $$ = new pf2asm::NE(LINE);   }
                | tUGT           { $$ = new pf2asm::UGT(LINE);  }
                | tUGE           { $$ = new pf2asm::UGE(LINE);  }
                | tULT           { $$ = new pf2asm::ULT(LINE);  }
                | tULE           { $$ = new pf2asm::ULE(LINE);  }
                | tDCMP          { $$ = new pf2asm::DCMP(LINE); }
                ;

jumps           : tBRANCH           { $$ = new pf2asm::BRANCH (LINE); }
                | tLEAP             { $$ = new pf2asm::LEAP   (LINE); }
                | tJMP  label       { $$ = new pf2asm::JMP    (LINE, *$2); delete $2; }
                | tJZ   label       { $$ = new pf2asm::JZ     (LINE, *$2); delete $2; }
                | tJNZ  label       { $$ = new pf2asm::JNZ    (LINE, *$2); delete $2; }
                | tJEQ  label       { $$ = new pf2asm::JEQ    (LINE, *$2); delete $2; }
                | tJNE  label       { $$ = new pf2asm::JNE    (LINE, *$2); delete $2; }
                | tJGT  label       { $$ = new pf2asm::JGT    (LINE, *$2); delete $2; }
                | tJGE  label       { $$ = new pf2asm::JGE    (LINE, *$2); delete $2; }
                | tJLT  label       { $$ = new pf2asm::JLT    (LINE, *$2); delete $2; }
                | tJLE  label       { $$ = new pf2asm::JLE    (LINE, *$2); delete $2; }
                | tJUGT label       { $$ = new pf2asm::JUGT   (LINE, *$2); delete $2; }
                | tJUGE label       { $$ = new pf2asm::JUGE   (LINE, *$2); delete $2; }
                | tJULT label       { $$ = new pf2asm::JULT   (LINE, *$2); delete $2; }
                | tJULE label       { $$ = new pf2asm::JULE   (LINE, *$2); delete $2; }
                ;

integer         : T_LIT_INT                       { $$ = $1; }
                | integer  '+'  integer           { $$ = $1 +  $3; }
                | integer  '-'  integer           { $$ = $1 -  $3; }
                | integer  '*'  integer           { $$ = $1 *  $3; }
                | integer  '/'  integer           { $$ = $1 /  $3; }
                | integer  '%'  integer           { $$ = $1 %  $3; }
                | integer  '<'  integer           { $$ = $1 <  $3; }
                | integer T_LE  integer           { $$ = $1 <= $3; }
                | integer T_EQ  integer           { $$ = $1 == $3; }
                | integer T_GE  integer           { $$ = $1 >= $3; }
                | integer  '>'  integer           { $$ = $1 >  $3; }
                | integer T_NE  integer           { $$ = $1 != $3; }
                | '!' integer                     { $$ = !$2; }
                | '-' integer %prec T_UMINUS      { $$ = -$2; }
                | '+' integer %prec T_UMINUS      { $$ =  $2; }
                | '(' integer ')'                 { $$ =  $2; }
                | integer '?' integer ':' integer { $$ = $1 ? $3 : $5; }
                ;

%%
