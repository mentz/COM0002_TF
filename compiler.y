%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token TIF TINT TELSE TFLOAT TPRINT TREAD TRETURN TSTRING TVOID TWHILE
%token TMEIG TMAIG TEQ TDIF TAND TOR
%token TID TLITERAL

%%

Programa 
	: ListaFuncoes BlocoPrincipal
	| BlocoPrincipal
	;

ListaFuncoes 
	: ListaFuncoes Funcao 
	| Funcao
	;

Funcao 
	: TipoRetorno TID '('DeclParametros')' BlocoPrincipal
	| TipoRetorno TID '('')' BlocoPrincipal 
	;

TipoRetorno 
	: Tipo
	| TVOID
	;

DeclParametros 
	: DeclParametros ',' Parametro
	| Parametro
	;

Parametro
	: Tipo TID
	;

BlocoPrincipal 
	: '{'Declaracoes ListaCmd'}'
	| '{'ListaCmd'}'
	;

Declaracoes 
	: Declaracoes Declaracao
	| Declaracao
	;

Declaracao 
	: Tipo ListaId';'
	;

Tipo
	: TINT
	| TSTRING
	| TFLOAT
	;

ListaId
	: ListaId ',' TID
	| TID
	;

Bloco 
	: '{'ListaCmd'}'
	;

ListaCmd 	
	: ListaCmd Comando 
	| Comando
	;
Comando 				
	: CmdSe
	| CmdEnquanto
	| CmdAtrib
	| CmdEscrita
	| CmdLeitura
	| ChamadaProc
	| Retorno
	;

Retorno 				
	: TRETURN ExpressaoAritmetica';'
	| TRETURN TLITERAL';'
	;
					
CmdSe
	: TIF '('ExpressaoLogica')' Bloco
	| TIF '('ExpressaoLogica')' Bloco TELSE Bloco
	;
				
CmdEnquanto 
	: TWHILE '('ExpressaoLogica')' Bloco
	;

CmdAtrib
	: TID '=' ExpressaoAritmetica';'
	| TID '=' TLITERAL ';'
	;
			
CmdEscrita 
	: TPRINT '('ExpressaoAritmetica')'';'
	| TPRINT '(' TLITERAL ')'';'
	;	
			
CmdLeitura
	: TREAD '('TID')'';'
	;

ChamadaProc
	: ChamadaFuncao';' 
	;

ChamadaFuncao			
	: TID '('ListaParametros')'
	| TID '('')'
	;

ListaParametros
	: ListaParametros',' ExpressaoAritmetica
	| ListaParametros',' TLITERAL
	| ExpressaoAritmetica
	| TLITERAL
	;				

ExpressaoRelacional	
	: ExpressaoAritmetica '<' ExpressaoAritmetica
	| ExpressaoAritmetica '>' ExpressaoAritmetica
	| ExpressaoAritmetica TMEIG ExpressaoAritmetica
	| ExpressaoAritmetica TMAIG ExpressaoAritmetica
	| ExpressaoAritmetica TEQ ExpressaoAritmetica
	| ExpressaoAritmetica TDIF ExpressaoAritmetica
	;

ExpressaoLogica		
	: ExpressaoLogica TAND ArgumentoLogico
	| ExpressaoLogica TOR ArgumentoLogico
	| ArgumentoLogico
	;

ArgumentoLogico		
	: '('ExpressaoLogica')'
	| '-' ArgumentoLogico
	| ExpressaoRelacional
  	;

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
	: '('ExpressaoAritmetica')'
	| '-' FatorAritmetico
	| ChamadaFuncao
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
