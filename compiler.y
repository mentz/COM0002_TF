%{
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define YYSTYPE struct Atributo
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
	: Tipo ListaId';' {insTabSim($1.tipo, $2.listaId);}
	;

Tipo
	: TINT {$$.tipo = T_INT;}
	| TSTRING {$$.tipo = T_STR;}
	| TFLOAT {$$.tipo = T_FLT;}
	;

ListaId
	: ListaId ',' TID {$$.listaId = insLista($1, $3.id);}
	| TID {$$.listaId = criarLista($1.id);}
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
	| '!' ArgumentoLogico
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
	printf("Linha %d: %s - antes %s\n", linha, str, yytext);
} 		 

int yywrap()
{
	return 1;
}
