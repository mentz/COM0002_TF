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
									  $1.tipo = consultaTipo($1.id);
									  if ($1.tipo == T_INT && $3.tipo == T_FLT) {
										  $$.ptr = criarNoAST(ATRIB, $1.ptr, f2iAST($3.ptr));
										  addError(ERR_0, linha);
									  }
									  else
									  if ($1.tipo == T_FLT && $3.tipo == T_INT) {
										  $$.ptr = criarNoAST(ATRIB, $1.ptr, i2fAST($3.ptr));
										  addError(ERR_0, linha);
									  }
									  else {
										  $$.ptr = criarNoAST(ATRIB, $1.ptr, $3.ptr);
								  		  $$.tipo = $1.tipo;
									  }
									  imprimePosOrdem($$.ptr);
									  printf("----------\n");}
	| TID '=' TLITERAL ';'
	;

CmdEscrita
	: TPRINT '(' ExpressaoAritmetica ')'';'
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
	: ExpressaoAritmetica '+' TermoAritmetico 	{if ($1.tipo == T_STR || $3.tipo == T_STR) {
											        addError(ERR_2, linha);
												    YYABORT;
										         }
											     else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
													 $$.ptr = criarNoAST(ADD, i2fAST($1.ptr), $3.ptr);
													 $$.tipo = T_FLT;
													 addError(ERR_1, linha);
												 }
												 else
												 if ($1.tipo == T_FLT && $3.tipo == T_INT) {
												 	 $$.ptr = criarNoAST(ADD, $1.ptr, i2fAST($3.ptr));
												 	 $$.tipo = T_FLT;
												 	 addError(ERR_1, linha);
												 }
												 else {
												 	 $$.ptr = criarNoAST(ADD, $1.ptr, $3.ptr);
												 	 $$.tipo = $1.tipo;
												 }}
	| ExpressaoAritmetica '-' TermoAritmetico 	{if ($1.tipo == T_STR || $3.tipo == T_STR) {
											        addError(ERR_2, linha);
												    YYABORT;
										         }
										    	 else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
													 $$.ptr = criarNoAST(SUB, i2fAST($1.ptr), $3.ptr);
													 $$.tipo = T_FLT;
													 addError(ERR_1, linha);
												 }
												 else
												 if ($1.tipo == T_FLT && $3.tipo == T_INT) {
												 	 $$.ptr = criarNoAST(SUB, $1.ptr, i2fAST($3.ptr));
												 	 $$.tipo = T_FLT;
												 	 addError(ERR_1, linha);
												 }
												 else {
												 	 $$.ptr = criarNoAST(SUB, $1.ptr, $3.ptr);
												 	 $$.tipo = $1.tipo;
												 }}
	| TermoAritmetico 							{$$.ptr = $1.ptr;}
	;

TermoAritmetico
	: TermoAritmetico '*' FatorAritmetico 	{if ($1.tipo == T_STR || $3.tipo == T_STR) {
											    addError(ERR_2, linha);
												YYABORT;
										     }
											 else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
												 $$.ptr = criarNoAST(MUL, i2fAST($1.ptr), $3.ptr);
												 $$.tipo = T_FLT;
												 addError(ERR_1, linha);
											 }
											 else if ($1.tipo == T_FLT && $3.tipo == T_INT) {
												 $$.ptr = criarNoAST(MUL, $1.ptr, i2fAST($3.ptr));
												 $$.tipo = T_FLT;
												 addError(ERR_1, linha);
											 }
											 else {
												 $$.ptr = criarNoAST(MUL, $1.ptr, $3.ptr);
												 $$.tipo = $1.tipo;
											 }}
	| TermoAritmetico '/' FatorAritmetico 	{if ($1.tipo == T_STR || $3.tipo == T_STR) {
											    addError(ERR_2, linha);
												YYABORT;
										     }
											 else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
												 $$.ptr = criarNoAST(DIV, i2fAST($1.ptr), $3.ptr);
												 $$.tipo = T_FLT;
												 addError(ERR_1, linha);
											 }
											 else if ($1.tipo == T_FLT && $3.tipo == T_INT) {
												 $$.ptr = criarNoAST(DIV, $1.ptr, i2fAST($3.ptr));
												 $$.tipo = T_FLT;
												 addError(ERR_1, linha);
											 }
											 else {
												 $$.ptr = criarNoAST(DIV, $1.ptr, $3.ptr);
												 $$.tipo = $1.tipo;
											 }}
	| FatorAritmetico 						{$$.ptr = $1.ptr; $$.tipo = $1.tipo;}
	;

FatorAritmetico
	: '('ExpressaoAritmetica')' {$$.tipo = $2.tipo;
	                             $$.ptr = $2.ptr;}
	| '-' FatorAritmetico 		{$$.tipo = $2.tipo;
	                             $$.ptr = criarNoAST(NEG, $2.ptr, NULL);}
	| ChamadaFuncao 			{$$.ptr = criarFolhaID(FUNCAO, $1.id);}
	| TINT 						{$$.tipo = T_INT;
	                             $$.ptr = criarFolhaInt(CONSTINT, $1.ival);}
	| TFLOAT 					{$$.tipo = T_FLT;
	                             $$.ptr = criarFolhaFloat(CONSTFLOAT, $1.fval);}
	| TID 						{$$.ptr = criarFolhaID(VAR, $1.id);
								 $$.tipo = consultaTipo($1.id);
								 if ($$.tipo == NAOEXISTE)
								 {
									 addError(ERR_3, linha);
									 YYABORT;
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
