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
	: TID '=' ExpressaoAritmetica';' {$1.ptr = criarFolhaID(VAR, $1.id);
									  $$.ptr = criarNoAST(ATRIB, $1.ptr, $3.ptr);
									  imprimePosOrdem($$.ptr);
									  printf("\n");}
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
	: ExpressaoAritmetica '+' TermoAritmetico 	{if ($1.tipo == CONSTINT && $3.tipo == CONSTFLOAT) {
													 $$.ptr = criarNoAST(MUL, i2fAST($1.ptr), $3.ptr);
													 $$.tipo = CONSTFLOAT;
													 printf("Warn: Cálculo com operandos de tipos diferentes\n");
												 }
												 else
												 if ($1.tipo == CONSTFLOAT && $3.tipo == CONSTINT) {
												 	 $$.ptr = criarNoAST(MUL, $1.ptr, i2fAST($3.ptr));
												 	 $$.tipo = CONSTFLOAT;
												 	 printf("Warn: Cálculo com operandos de tipos diferentes\n");
												 }
												 else {
												 	 $$.ptr = criarNoAST(MUL, $1.ptr, $3.ptr);
												 	 $$.tipo = $1.tipo;
												 }}
	| ExpressaoAritmetica '-' TermoAritmetico 	{if ($1.tipo == CONSTINT && $3.tipo == CONSTFLOAT) {
													 $$.ptr = criarNoAST(MUL, i2fAST($1.ptr), $3.ptr);
													 $$.tipo = CONSTFLOAT;
													 printf("Warn: Cálculo com operandos de tipos diferentes\n");
												 }
												 else
												 if ($1.tipo == CONSTFLOAT && $3.tipo == CONSTINT) {
												 	 $$.ptr = criarNoAST(MUL, $1.ptr, i2fAST($3.ptr));
												 	 $$.tipo = CONSTFLOAT;
												 	 printf("Warn: Cálculo com operandos de tipos diferentes\n");
												 }
												 else {
												 	 $$.ptr = criarNoAST(MUL, $1.ptr, $3.ptr);
												 	 $$.tipo = $1.tipo;
												 }}
	| TermoAritmetico 							{$$.ptr = $1.ptr;}
	;

TermoAritmetico
	: TermoAritmetico '*' FatorAritmetico 	{if ($1.tipo == CONSTINT && $3.tipo == CONSTFLOAT) {
												 $$.ptr = criarNoAST(MUL, i2fAST($1.ptr), $3.ptr);
												 $$.tipo = CONSTFLOAT;
												 printf("Warn: Cálculo com operandos de tipos diferentes\n");
											 }
											 else
											 if ($1.tipo == CONSTFLOAT && $3.tipo == CONSTINT) {
												 $$.ptr = criarNoAST(MUL, $1.ptr, i2fAST($3.ptr));
												 $$.tipo = CONSTFLOAT;
												 printf("Warn: Cálculo com operandos de tipos diferentes\n");
											 }
											 else {
												 $$.ptr = criarNoAST(MUL, $1.ptr, $3.ptr);
												 $$.tipo = $1.tipo;
											 }}
	| TermoAritmetico '/' FatorAritmetico 	{if ($1.tipo == CONSTINT && $3.tipo == CONSTFLOAT) {
												 $$.ptr = criarNoAST(DIV, i2fAST($1.ptr), $3.ptr);
												 $$.tipo = CONSTFLOAT;
												 printf("Warn: Cálculo com operandos de tipos diferentes\n");
											 }
											 else
											 if ($1.tipo == CONSTFLOAT && $3.tipo == CONSTINT) {
												 $$.ptr = criarNoAST(DIV, $1.ptr, i2fAST($3.ptr));
												 $$.tipo = CONSTFLOAT;
												 printf("Warn: Cálculo com operandos de tipos diferentes\n");
											 }
											 else {
												 $$.ptr = criarNoAST(DIV, $1.ptr, $3.ptr);
												 $$.tipo = $1.tipo;
											 }}
	| FatorAritmetico 						{$$.ptr = $1.ptr; $$.tipo = $1.tipo;}
	;

FatorAritmetico
	: '('ExpressaoAritmetica')' {$$.ptr = $2.ptr; $$.tipo = $2.tipo;}
	| '-' FatorAritmetico 		{$$.ptr = criarNoAST(NEG, $2.ptr, NULL); $$.tipo = $2.tipo;}
	| ChamadaFuncao 			{$$.ptr = criarFolhaID(FUNCAO, $1.id);}
	| TINT 						{$$.ptr = criarFolhaInt(CONSTINT, $1.ival); $$.tipo = T_INT;}
	| TFLOAT 					{$$.ptr = criarFolhaFloat(CONSTFLOAT, $1.fval); $$.tipo = T_FLT;}
	| TID 						{$$.ptr = criarFolhaID(VAR, $1.id);
								 $$.tipo = consultaTipo($1.id);
								 if ($$.tipo == T_STR) {
									 printf("Erro: Aritmética com string não permitida\n");
									 exit(EXIT_FAILURE);
								 }}
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
