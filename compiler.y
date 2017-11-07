%{
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define YYSTYPE struct Atributo

int linha = 1;
extern struct Simbolo *tabsim;

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
	: ListaId ',' TID {$$.listaId = insLista(&$1, $3.id);}
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
	: TID '=' ExpressaoAritmetica';' {imprimePosOrdem($3.ptr); putchar('\n');}
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
	: ExpressaoAritmetica '+' TermoAritmetico 	{$$.ptr = criarNoAST(ADD, $1.ptr, $3.ptr);}
	| ExpressaoAritmetica '-' TermoAritmetico 	{$$.ptr = criarNoAST(SUB, $1.ptr, $3.ptr);}
	| TermoAritmetico 							{$$.ptr = $1.ptr;}
	;

TermoAritmetico
	: TermoAritmetico '*' FatorAritmetico 	{$$.ptr = criarNoAST(MUL, $1.ptr, $3.ptr);}
	| TermoAritmetico '/' FatorAritmetico 	{$$.ptr = criarNoAST(DIV, $1.ptr, $3.ptr);}
	| FatorAritmetico 						{$$.ptr = $1.ptr;}
	;

FatorAritmetico
	: '('ExpressaoAritmetica')' {$$.ptr = $2.ptr;}
	| '-' FatorAritmetico 		{$$.ptr = criarNoAST(NEG, $2.ptr, NULL);}
	| ChamadaFuncao 			{$$.ptr = criarFolhaID(FUNCAO, $1.id);}
	| TINT 						{$$.ptr = criarFolhaInt(CONSTINT, $1.ival);}
	| TFLOAT 					{$$.ptr = criarFolhaFloat(CONSTFLOAT, $1.fval);}
	| TID 						{$$.ptr = criarFolhaID(VAR, $1.id);}
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
