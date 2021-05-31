%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE               compiler->scanner()->lineno()
#define yylex()            compiler->scanner()->scan()
#define yyerror(s)         compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!

#define NIL (new cdk::nil_node(LINE))
%}

%union {
  int                   i;  /* integer value */
  double                d;  /* integer value */
  std::string          *s;  /* symbol name or string literal */
  cdk::basic_node      *node; /* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  
  basic_type           *type;       /* expression type */

  gr8::block_node      *block;
}

%token tPRIVATE tUSE tPUBLIC tPRINTLN
%token tWHILE tSWEEP tNEXT tSTOP
%token tIF tELSIF tTHEN tELSE

%token tINT_TYPE tREAL_TYPE tSTRING_TYPE
%token tPROCEDURE tRETURN

%token tBLKOPEN tBLKCLOSE tNL tPRINTLN

%token tSMALL tHUGE tFAKE tNEWS tINITIALLY tIF tTHEN tELSE 
%token tSWEEPING tFROM tTO tBY tDO tSTOP tAGAIN tRETURN
%token tSLIGHTLY tABOVE tBELOW tIS tNOT
%token tTIMES tOVER tPLUS tMINUS tMODULUS tASSIGN tTO
%token tDEFINE tPROCEDURE tFUNCTION tON tAS tUSES
%token tPOST tTWEET tUSE tFOR tINPUT tOBJECTS

%token tCELL tAT

%token<i> tINTEGER
%token<d> tREAL
%token<s> tSTRING tID
%token<expression> tNULLPTR;

%type<node> declaration instruction blktion elsif
%type<sequence> args expressions 
%type<sequence> file declarations innerdecls instructions opt_instructions
%type<expression> expression integer real 
%type<lvalue> lvalue
%type<block> block

%type<s> string
%type<type> data_type small_fake small_reps huge_fake huge_reps fake_news
%type<node> vardecl fundecl fundef

%nonassoc tIF tWHILE
%nonassoc tTHEN tDO
%nonassoc tELSIF tELSE

%left '|'
%left '&'
%right tNOT
%left tEQ
%left '<' '>'
%left '+' '-'
%left '*' '/' '%'
%right tUMINUS
%nonassoc '?' tOBJECTS

%%
file           : /* empty */  { compiler->ast($$ = new cdk::sequence_node(LINE)); }
               | declarations { compiler->ast($$ = $1); }
               ;

declarations   :              declaration { $$ = new cdk::sequence_node(LINE, $1);     }
               | declarations declaration { $$ = new cdk::sequence_node(LINE, $2, $1); }
               ;

declaration    : vardecl ';' { $$ = $1; }
               | fundecl ';' { $$ = $1; }
               | fundef      { $$ = $1; }
               ;

vardecl  : tPUBLIC data_type tID             { $$ = new gr8::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, nullptr); delete $3; }
         | tPUBLIC data_type tID '(' tINITIALLY expression ')' { $$ = new gr8::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, $6); delete $3; }
         | tUSE    data_type tID             { $$ = new gr8::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, nullptr); delete $3; }
         |         data_type tID             { $$ = new gr8::variable_declaration_node(LINE, tPRIVATE, $1, *$2, nullptr); delete $2;}
         |         data_type tID '(' tINITIALLY expression ')' { $$ = new gr8::variable_declaration_node(LINE, tPRIVATE, $1, *$2, $5); delete $2;}
         ;
       
data_type    : small_fake            { $$ = $1; }
             | huge_fake             { $$ = $1; }
             | fake_news             { $$ = $1; }
             ;

small_fake   : tINT_TYPE         { $$ = new basic_type(4, basic_type::TYPE_INT);    }
             | small_reps tFAKE  { $$ = $1; }
             ;

small_reps    : tINT_TYPE            { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = new basic_type(4, basic_type::TYPE_INT); }
             | small_reps tINT_TYPE  { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $1; }
             ;

huge_fake    : tREAL_TYPE       { $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
             | huge_reps tFAKE  { $$ = $1; }
             ;

huge_reps    : tREAL_TYPE            { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = new basic_type(8, basic_type::TYPE_DOUBLE); }
             | huge_reps tREAL_TYPE  { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $1; }
             ;

fake_news    : tSTRING_TYPE          { $$ = new basic_type(4, basic_type::TYPE_STRING); }
             | tFAKE fake_news       { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $2; }
             ;

fundecl  :         data_type tFUNCTION  tID            { $$ = new gr8::function_declaration_node(LINE, tPRIVATE, $1, *$3, nullptr); delete $3; }
         |                   tPROCEDURE tID            { $$ = new gr8::function_declaration_node(LINE, tPRIVATE,     *$2, nullptr); delete $2; }
         | tPUBLIC data_type tFUNCTION  tID            { $$ = new gr8::function_declaration_node(LINE, tPUBLIC,  $2, *$4, nullptr); delete $4; }
         | tPUBLIC           tPROCEDURE tID            { $$ = new gr8::function_declaration_node(LINE, tPUBLIC,      *$3, nullptr); delete $3; }
         
         |         data_type tFUNCTION  tID tUSES args { $$ = new gr8::function_declaration_node(LINE, tPRIVATE, $1, *$3, $5); delete $3; }
         |                   tPROCEDURE tID tUSES args { $$ = new gr8::function_declaration_node(LINE, tPRIVATE,     *$2, $4); delete $2; }
         | tPUBLIC data_type tFUNCTION  tID tUSES args { $$ = new gr8::function_declaration_node(LINE, tPUBLIC,  $2, *$4, $6); delete $4; }
         | tPUBLIC           tPROCEDURE tID tUSES args { $$ = new gr8::function_declaration_node(LINE, tPUBLIC,      *$3, $5); delete $3; }
         ;
         
fundef   : tDEFINE         data_type tFUNCTION tID tAS block
         {
           $$ = new gr8::function_definition_node(LINE, tPRIVATE, $2, *$4, nullptr, $6);
           delete $4;
         }
         | tDEFINE tPUBLIC data_type tFUNCTION tID tAS block
         {
           $$ = new gr8::function_definition_node(LINE, tPUBLIC, $3, *$5, nullptr, $7);
           delete $5;
         }
         
         | tDEFINE         data_type tFUNCTION tID tON args tAS block
         {
           $$ = new gr8::function_definition_node(LINE, tPRIVATE, $2, *$4, $6, $8);
           delete $4;
         }
         | tDEFINE tPUBLIC data_type tFUNCTION tID tON args tAS block
         {
           $$ = new gr8::function_definition_node(LINE, tPUBLIC, $3, *$5, $7, $9);
           delete $5;
         }
         
         
         
         | tDEFINE         tPROCEDURE tID tAS block { $$ = new gr8::function_definition_node(LINE, tPRIVATE, *$3, nullptr, $5); delete $3; }
         | tDEFINE tPUBLIC tPROCEDURE tID tAS block { $$ = new gr8::function_definition_node(LINE, tPUBLIC,  *$4, nullptr, $6); delete $4; }
         
         | tDEFINE         tPROCEDURE tID tON args tAS block { $$ = new gr8::function_definition_node(LINE, tPRIVATE, *$3, $5, $7); delete $3; }
         | tDEFINE tPUBLIC tPROCEDURE tID tON args tAS block { $$ = new gr8::function_definition_node(LINE, tPUBLIC,  *$4, $6, $8); delete $4; }
         ;

args     : vardecl           { $$ = new cdk::sequence_node(LINE, $1);     }
         | args ',' vardecl  { $$ = new cdk::sequence_node(LINE, $3, $1); }
         ;

block: '{'            opt_instructions '}' {
         $$ = new gr8::block_node(LINE, nullptr, $2);
     }
     | '{' innerdecls opt_instructions '}' {
         $$ = new gr8::block_node(LINE, $2, $3);
     }
     ;

innerdecls      :            vardecl ';' { $$ = new cdk::sequence_node(LINE, $1);     }
                | innerdecls vardecl ';' { $$ = new cdk::sequence_node(LINE, $2, $1); }
                ;

opt_instructions: /* empty */  { $$ = new cdk::sequence_node(LINE); }
                | instructions { $$ = $1; }
                ;

instructions    : instruction               { $$ = new cdk::sequence_node(LINE, $1);     }
                | blktion                   { $$ = new cdk::sequence_node(LINE, $1);     }
                | instruction ';' instructions   { std::reverse($3->nodes().begin(), $3->nodes().end()); $$ = new cdk::sequence_node(LINE, $1, $3); std::reverse($$->nodes().begin(), $$->nodes().end()); }
                | blktion instructions { std::reverse($2->nodes().begin(), $2->nodes().end()); $$ = new cdk::sequence_node(LINE, $1, $2); std::reverse($$->nodes().begin(), $$->nodes().end()); }
                ;

blktion         : tIF expression tTHEN block        { $$ = new gr8::if_node(LINE, $2, $4); }
                | tIF expression tTHEN block elsif  { $$ = new gr8::if_else_node(LINE, $2, $4, $5); }
                | tSWEEPING lvalue tFROM expression tTO expression tDO block                 { $$ = new gr8::sweep_node(LINE, $2, $4, $6, new cdk::integer_node(LINE, 1), $8); }
                | tSWEEPING lvalue tFROM expression tTO expression tBY expression tDO block  { $$ = new gr8::sweep_node(LINE, $2, $4, $6, $8, $10); }
                | block                           { $$ = $1; }
                ;

instruction     : expression                      { $$ = new gr8::evaluation_node(LINE, $1); }
                | tTWEET expression               { $$ = new gr8::print_node(LINE, $2, false); }
                | tPOST  expression               { $$ = new gr8::print_node(LINE, $2, true); }
                | tSTOP                           { $$ = new gr8::stop_node(LINE);  }
                | tSTOP  tINTEGER                 { $$ = new gr8::stop_node(LINE, $2);  }
                | tAGAIN                          { $$ = new gr8::next_node(LINE); }
                | tAGAIN tINTEGER                 { $$ = new gr8::next_node(LINE, $2); }
                | tASSIGN expression tTO lvalue   { $$ = new cdk::assignment_node(LINE, $4, $2); }
                | tRETURN               { $$ = new gr8::return_node(LINE, nullptr); }
                | tRETURN expression    { $$ = new gr8::return_node(LINE, $2);      }
                ;

elsif           : tELSE block                               { $$ = $2; }
                | tELSIF expression tTHEN block             { $$ = new gr8::if_node(LINE, $2, $4); }
                | tELSIF expression tTHEN block elsif       { $$ = new gr8::if_else_node(LINE, $2, $4, $5); }
                ;

lvalue          : tID                                              { $$ = new cdk::identifier_node(LINE, $1); }
                | tCELL expression tAT lvalue                      { $$ = new gr8::left_index_node(LINE, new cdk::rvalue_node(LINE, $4), $2);}
                | tCELL expression tAT     '('     expression  ')' { $$ = new gr8::left_index_node(LINE, $5, $2);}
                | tCELL expression tAT tDO tID                     { $$ = new gr8::left_index_node(LINE, $2, new gr8::function_call_node(LINE, *$5, nullptr)); delete $5; }
                | tCELL expression tAT tUSE expressions tFOR tID   { $$ = new gr8::left_index_node(LINE, $2, new gr8::function_call_node(LINE, *$7, $5)); delete $7; }
                ;

expression      : integer                       { $$ = $1; }
                | real                          { $$ = $1; }
                | string                        { $$ = new cdk::string_node(LINE, $1); }
                | tNULL                         { $$ = new gr8::nullptr_node(LINE); }
                /* LEFT VALUES */
                | lvalue                      { $$ = new cdk::rvalue_node(LINE, $1); }
                /* ARITHMETIC EXPRESSIONS */
                | expression '+' expression    { $$ = new cdk::add_node(LINE, $1, $3); }
                | expression '-' expression    { $$ = new cdk::sub_node(LINE, $1, $3); }
                | expression '*' expression    { $$ = new cdk::mul_node(LINE, $1, $3); }
                | expression '/' expression    { $$ = new cdk::div_node(LINE, $1, $3); }
                | expression '%' expression    { $$ = new cdk::mod_node(LINE, $1, $3); }
                /* LOGICAL EXPRESSIONS */
                | expression  '<' expression    { $$ = new cdk::lt_node(LINE, $1, $3); }
                | expression tEQ  expression    { $$ = new cdk::eq_node(LINE, $1, $3); }
                | expression  '>' expression    { $$ = new cdk::gt_node(LINE, $1, $3); }
                /* LOGICAL EXPRESSIONS */
                | expression '&'  expression    { $$ = new cdk::and_node(LINE, $1, $3); }
                | expression '|'  expression    { $$ = new cdk::or_node (LINE, $1, $3); }
                /* UNARY EXPRESSION */
                | '-' expression %prec tUMINUS  { $$ = new cdk::neg_node(LINE, $2); }
                | '+' expression %prec tUMINUS  { $$ = $2; }
                | tNOT expression               { $$ = new cdk::not_node(LINE, $2); }
                /* OTHER EXPRESSION */
                | tINPUT                        { $$ = new gr8::read_node(LINE); }
                /* OTHER EXPRESSION */
                | tDO tID                       { $$ = new gr8::function_call_node(LINE, *$2, nullptr); delete $2; }
                | tUSE expressions tFOR tID     { $$ = new gr8::function_call_node(LINE, *$4, $2);      delete $4; }
                /* OTHER EXPRESSION */
                | '(' expression ')'            { $$ = $2; }
                | expression tOBJECTS           { $$ = new gr8::stack_alloc_node(LINE, $1); }
                | lvalue '?'                    { $$ = new gr8::address_of_node(LINE, $1); }
                ;

expressions     : expression                     { $$ = new cdk::sequence_node(LINE, $1);     }
                | expressions ',' expression     { $$ = new cdk::sequence_node(LINE, $3, $1); }
                ;

integer         : tINTEGER                      { $$ = new cdk::integer_node(LINE, $1); };
real            : tREAL                         { $$ = new cdk::double_node(LINE, $1); };
string          : tSTRING                       { $$ = $1; }
                | string tSTRING                { $$ = new std::string(*$1 + *$2); delete $1; delete $2; }
                ;

%%
