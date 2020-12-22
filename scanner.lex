%{
    #include <stdio.h>
    #include "source.h"
    #define YYSTYPE NonTerminal
    #include "parser.tab.hpp"
    #include "hw3_output.hpp"
%}

%option yylineno
%option noyywrap


relop_equality          ((\=\=)|(\!\=))
relop_relational        ((\<)|(\>)|(\<\=)|(\>\=)|in)
binop_additive          (\+|\-)
binop_multiplicative    (\*|\/|\%)
comment                 (\/\/[^\r\n]*[\r|\n|\r\n]?)
dec_digit               ([0-9])
hex_digit               ([0-9a-fA-F])
num                     (0|[1-9][0-9]*)
escape_param            ([\\\"nrt0]|(x[0-7]{hex_digit}))
good_string             (\"([^\n\r\"\\]|\\[rnt\"\\])+\")
letter  	            ([a-zA-Z])
id                      ([a-zA-Z][a-zA-Z0-9]*)
new_line                ($|[\r\n])
space                   [\ \t\r\n]

%%

void                        return VOID;
int                         return INT;
byte                        return BYTE;
b                           return B;
bool                        return BOOL;
set                         return SET;
and                         return AND;
or                          return OR;
not                         return NOT;
true                        return TRUE;
false                       return FALSE;
return                      return RETURN;
if                          return IF;
else                        return ELSE;
while                       return WHILE;
break                       return BREAK;
continue                    return CONTINUE;
;                           return SC;
,                           return COMMA;
\(                          return LPAREN;
\)                          return RPAREN;
\{                          return LBRACE;
\}                          return RBRACE;
\[                          return LBRACKET;
\]                          return RBRACKET;
\=                          return ASSIGN;
\.\.                        return DOTS;
{relop_relational}          return RELOP_RELATIONAL;
{relop_equality}            return RELOP_EQUALITY;
{binop_multiplicative}      return BINOP_MULTIPLICATIVE;
{binop_additive}            return BINOP_ADDITIVE;
{comment}                   ;
{id}                        {yylval = NonTerminal(yytext, ""); return ID;}
{num}                       return NUM;
{good_string}               return STRING;
{space}                     ;
.                           output::errorLex(yylineno); exit(0);

%%


