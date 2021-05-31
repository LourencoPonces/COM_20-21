%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include "ast/all.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
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

  int                   i;	                   /* integer value */
  double                d;                       /* float value */
  std::string          *s;	                   /* symbol name or string literal */
  cdk::basic_node      *node;	                   /* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression;              /* expression nodes */
  cdk::lvalue_node     *lvalue;
  std::vector<std::string> *ids;
  fir::block_node          *block;
  fir::body_node           *body;
  fir::prologue_node       *prologue;
};

%token tTYPE_INT tTYPE_FLOAT tTYPE_STRING tTYPE_VOID tSIZEOF
%token tREQUIRE
%token tIF tTHEN tELSE
%token tWHILE tDO tFINALLY tLEAVE tRESTART
%token tGE tLE tEQ tNE tAND tOR 
%token tRETURN tWRITE tWRITELN
%token tRET_VAL tEPILOGUE

%token<i> tINTEGER
%token<d> tFLOAT
%token<s> tIDENTIFIER tSTRING
%token<expression> tNULL

%nonassoc tIF 
%nonassoc tTHEN 
%nonassoc tELSE

%nonassoc tWHILE
%nonassoc tDO
%nonassoc tFINALLY

%right '='
%left tOR
%left tAND
%nonassoc '~'
%left tEQ tNE
%left '<' '>' tLE tGE
%left '+' '-'
%left '*' '/' '%'
%nonassoc tUNARY 
%nonassoc '['

%type<sequence>    file declarations variables args instructions expressions opt_variables opt_instructions
%type<node>        declaration variable function func_decl func_def arg instruction
%type<expression>  opt_initializer def_ret_val literal integer float expression
%type<block>       epilogue block
%type<body>        body 
%type<prologue>    prologue
%type<lvalue>      lvalue

%type<type> data_type
%type<s> string


%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file             : declarations                                                    { compiler->ast($$ = $1); }
                 ;

declarations     :              declaration                                        { $$ = new cdk::sequence_node(LINE, $1);     }
                 | declarations declaration                                        { $$ = new cdk::sequence_node(LINE, $2, $1); }
                 ;

declaration      : variable ';'                                                    { $$ = $1; }
                 | function                                                        { $$ = $1; }
                 ;  
 
variable         : data_type '*' tIDENTIFIER opt_initializer                       { $$ = new fir::variable_definition_node(LINE, $1, 1, *$3, $4); }
                 | data_type     tIDENTIFIER opt_initializer                       { $$ = new fir::variable_definition_node(LINE, $1, 0, *$2, $3); }
                 | data_type '?' tIDENTIFIER                                       { $$ = new fir::variable_definition_node(LINE, $1, 2, *$3, nullptr); }
                 ;

variables        : variable ';'                                                    { $$ = new cdk::sequence_node(LINE, $1);     }
                 | variables variable ';'                                          { $$ = new cdk::sequence_node(LINE, $2, $1); }

opt_variables    : /* empty */                                                     { $$ = NULL; }
                 | variables                                                       { $$ = $1; }
                 ;

opt_initializer  : /* empty */                                                     { $$ = nullptr; }
                 | '=' expression                                                  { $$ = $2; }
                 ;
    
function         : func_decl                                                       { $$ = $1; }
                 | func_def                                                        { $$ = $1; }
                 ;
         
func_decl        : data_type  '*' tIDENTIFIER '(' args ')'                         { $$ = new fir::function_declaration_node(LINE, $1, 1,  *$3, $5); }
                 | data_type      tIDENTIFIER '(' args ')'                         { $$ = new fir::function_declaration_node(LINE, $1, 0, *$2, $4); }
                 | data_type  '?' tIDENTIFIER '(' args ')'                         { $$ = new fir::function_declaration_node(LINE, $1, 2, *$3, $5); }
                 | tTYPE_VOID '*' tIDENTIFIER '(' args ')'                         { $$ = new fir::function_declaration_node(LINE,     1,  *$3, $5); }
                 | tTYPE_VOID     tIDENTIFIER '(' args ')'                         { $$ = new fir::function_declaration_node(LINE,     0, *$2, $4); }
                 | tTYPE_VOID '?' tIDENTIFIER '(' args ')'                         { $$ = new fir::function_declaration_node(LINE,     2, *$3, $5); }
                 ;

func_def         : data_type  '*' tIDENTIFIER '(' args ')' def_ret_val body        { $$ = new fir::function_definition_node(LINE, $1, 1,  *$3, $5, $7, $8); }
                 | data_type      tIDENTIFIER '(' args ')' def_ret_val body        { $$ = new fir::function_definition_node(LINE, $1, 0, *$2, $4, $6, $7); }
                 | data_type  '*' tIDENTIFIER '(' args ')'             body        { $$ = new fir::function_definition_node(LINE,     1,  *$3, $5,     $7); }
                 | data_type      tIDENTIFIER '(' args ')'             body        { $$ = new fir::function_definition_node(LINE,     0, *$2, $4,     $6); }
                 | tTYPE_VOID '*' tIDENTIFIER '(' args ')'             body        { $$ = new fir::function_definition_node(LINE,     1,  *$3, $5,     $7); }
                 | tTYPE_VOID     tIDENTIFIER '(' args ')'             body        { $$ = new fir::function_definition_node(LINE,     0, *$2, $4,     $6); }
                 ;

args             : /* empty */                                                     { $$ = new cdk::sequence_node(LINE);  }
                 | arg                                                             { $$ = new cdk::sequence_node(LINE, $1);     }
                 | args ',' arg                                                    { $$ = new cdk::sequence_node(LINE, $3, $1); }
                 ;

arg              : data_type tIDENTIFIER                                           { $$ = new fir::variable_definition_node(LINE, $1, 0, *$2, nullptr); }
                 ;

def_ret_val      : tRET_VAL literal                                                { $$ = $2; }
                 ;

literal          : integer                                                         { $$ = $1; }
                 | float                                                           { $$ = $1; }
                 | string                                                          { $$ = new cdk::string_node(LINE, $1); }
                 | tNULL                                                           { $$ = new fir::null_node(LINE); }
                 ;

body             : prologue                                                        { $$ = new fir::body_node(LINE, $1,      nullptr, nullptr); }
                 | block                                                           { $$ = new fir::body_node(LINE, nullptr, $1,      nullptr); }
                 | epilogue                                                        { $$ = new fir::body_node(LINE, nullptr, nullptr, $1); }
                 | prologue block                                                  { $$ = new fir::body_node(LINE, $1,      $2,      nullptr); }
                 | prologue epilogue                                               { $$ = new fir::body_node(LINE, $1,      nullptr, $2); }
                 | block epilogue                                                  { $$ = new fir::body_node(LINE, nullptr, $1,      $2); }
                 | prologue block epilogue                                         { $$ = new fir::body_node(LINE, $1,      $2,      $3); }
                 ;

prologue         : '@' block                                                       { $$ = new fir::prologue_node(LINE, $2); }
                 ;

epilogue         : tEPILOGUE block                                                 { $$ = $2; }
                 ;

block            : '{' opt_variables opt_instructions '}'                          { $$ = new fir::block_node(LINE, $2, $3); }
                 ;

instruction      : tIF expression tTHEN instruction                                { $$ = new fir::if_node(LINE, $2, $4); }
                 | tIF expression tTHEN instruction tELSE instruction              { $$ = new fir::if_else_node(LINE, $2, $4, $6); }
                 | tWHILE expression tDO instruction                               { $$ = new fir::while_node(LINE, $2, $4); }
                 | tWHILE expression tDO instruction tFINALLY instruction          { $$ = new fir::while_finally_node(LINE, $2, $4, $6); }
                 | expression ';'                                                  { $$ = new fir::evaluation_node(LINE, $1); }
                 | tWRITE   expressions ';'                                        { $$ = new fir::write_node(LINE, $2, false); }
                 | tWRITELN expressions ';'                                        { $$ = new fir::write_node(LINE, $2, true); }
                 | tLEAVE ';'                                                      { $$ = new fir::leave_node(LINE); }
                 | tLEAVE tINTEGER ';'                                             { $$ = new fir::leave_node(LINE, $2); }
                 | tRESTART ';'                                                    { $$ = new fir::restart_node(LINE); }
                 | tRESTART tINTEGER ';'                                           { $$ = new fir::restart_node(LINE, $2); }
                 | tRETURN                                                         { $$ = new fir::return_node(LINE); }
                 | block                                                           { $$ = $1; }
                 ;

instructions     : instruction                                                     { $$ = new cdk::sequence_node(LINE, $1); }
                 | instructions instruction                                        { $$ = new cdk::sequence_node(LINE, $2, $1); }
                 ;

opt_instructions : /* empty */                                                     { $$ = new cdk::sequence_node(LINE); }
                 | instructions                                                    { $$ = $1; }
                 ;

data_type        : tTYPE_STRING                                                    { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
                 | tTYPE_INT                                                       { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
                 | tTYPE_FLOAT                                                     { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
                 | '<' data_type '>'                                               { $$ = cdk::reference_type::create(4, $2); }
                 ;

integer          : tINTEGER                                                        { $$ = new cdk::integer_node(LINE, $1); }
                 ;

float            : tFLOAT                                                          { $$ = new cdk::double_node(LINE, $1); }
                 ;

string           : tSTRING                                                         { $$ = $1; }
                 | string tSTRING                                                  { $$ = $1; $$->append(*$2); delete $2; }
                 ;
               
expression       : literal                                                         { $$ = $1; }
                 /* PRIMARY */
                 | '(' expression ')'                                              { $$ = $2; }
                 | '[' expression ']'                                              { $$ = new fir::stack_alloc_node(LINE, $2); }
                 /* UNARY EXPRESSION */
                 | '+' expression %prec tUNARY                                     { $$ = $2; }
                 | '-' expression %prec tUNARY                                     { $$ = new cdk::neg_node(LINE, $2); }
                 | lvalue '?'                                                      { $$ = new fir::address_of_node(LINE, $1); }
                 /* ARITHMETIC EXPRESSIONS */
                 | expression '*' expression                                       { $$ = new cdk::mul_node(LINE, $1, $3); }
                 | expression '/' expression                                       { $$ = new cdk::div_node(LINE, $1, $3); }
                 | expression '%' expression                                       { $$ = new cdk::mod_node(LINE, $1, $3); }
                 | expression '+' expression                                       { $$ = new cdk::add_node(LINE, $1, $3); }
                 | expression '-' expression                                       { $$ = new cdk::sub_node(LINE, $1, $3); }
                 /* LOGICAL EXPRESSIONS */
                 | expression  '<' expression                                      { $$ = new cdk::lt_node(LINE, $1, $3); }
                 | expression  '>' expression                                      { $$ = new cdk::gt_node(LINE, $1, $3); }
                 | expression tLE  expression                                      { $$ = new cdk::le_node(LINE, $1, $3); }
                 | expression tGE  expression                                      { $$ = new cdk::ge_node(LINE, $1, $3); }
                 | expression tEQ  expression                                      { $$ = new cdk::eq_node(LINE, $1, $3); }
                 | expression tNE  expression                                      { $$ = new cdk::ne_node(LINE, $1, $3); }
                 | '~' expression                                                  { $$ = new cdk::not_node(LINE, $2); }
                 | expression tAND  expression                                     { $$ = new cdk::and_node(LINE, $1, $3); }
                 | expression tOR   expression                                     { $$ = new cdk::or_node (LINE, $1, $3); }
                 /* ASSIGNMENTS */
                 | lvalue '=' expression                                           { $$ = new cdk::assignment_node(LINE, $1, $3); }
                 /* LEFT VALUES */
                 | lvalue                                                          { $$ = new cdk::rvalue_node(LINE, $1); }
                 /* OTHER EXPRESSION */
                 | tIDENTIFIER '(' /* empty */ ')'                                 { $$ = new fir::function_call_node(LINE, *$1    ); delete $1; }
                 | tIDENTIFIER '(' expressions ')'                                 { $$ = new fir::function_call_node(LINE, *$1, $3); delete $1; }
                 | '@'                                                             { $$ = new fir::read_node(LINE); }
                 | tSIZEOF '(' expression ')'                                      { $$ = new fir::sizeof_node(LINE, $3); }
                 ;

expressions      : expression                                                      { $$ = new cdk::sequence_node(LINE, $1);     }
                 | expressions ',' expression                                      { $$ = new cdk::sequence_node(LINE, $3, $1); }
                 ;     

lvalue           : tIDENTIFIER                                                     { $$ = new cdk::variable_node(LINE, *$1); delete $1; }
                 | expression '[' expression ']'                                   { $$ = new fir::index_node(LINE, $1, $3); }
                 ;

%%
