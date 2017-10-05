%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token TIF TINT TELSE TFLOAT TPRINT TREAD TSTRING TVOID TWHILE
%token TMEIG TMAIG TEQ TDIF TAND TOR
%token TID TLITERAL

%%
ExpressaoAritmetica
	: ExpressaoAritmetica '+' TermoAritmetico
	| ExpressaoAritmetica '-' TermoAritmetico
	| TermoAritmetico
	;

TermoAritmetico
	: TermoAritmetico '*' FatorAritmetico
	| TermoAritmetico '/' FatorAritmetico
	| FatorAritmetico
	;

FatorAritmetico
	: '(' ExpressaoAritmetica ')'
	| '-' FatorAritmetico
	| TINT
	| TFLOAT
	| TID
	;
%%
#include "lex.yy.c"

int yyerror (char *str)
{
	printf("%s - antes %s\n", str, yytext);
	
} 		 

int yywrap()
{
	return 1;
}
