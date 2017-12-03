%{
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define YYSTYPE struct Atributo

int linha = 1;
extern struct Simbolo *tabSim;

%}

%token TDO TIF TINT TELSE TFLOAT TPRINT TREAD TRETURN TSTRING TVOID TWHILE
%token TMEIG TMAIG TEQ TDIF TAND TOR
%token TID TLITERAL

%%

Programa
	: ListaFuncoes BlocoPrincipal
	| BlocoPrincipal
	{
		printInicioArquivo();
		printAST($1.ptr);
		printFinalMain();
	}
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
	{
		//$$.ptr = criarNoAST(AST_BLOCO, $2.ptr, $3.ptr);
		$$.ptr = $3.ptr;
	}
	| '{'ListaCmd'}'
	{
		$$.ptr = $2.ptr;
	}
	;

Declaracoes
	: Declaracoes Declaracao
	| Declaracao
	;

Declaracao
	: Tipo ListaId';'
	{
		insTabSim($1.tipo, $2.listaId);
	}
	;

Tipo
	: TINT
	{
		$$.tipo = T_INT;
	}
	| TSTRING
	{
		$$.tipo = T_STR;
	}
	| TFLOAT
	{
		$$.tipo = T_FLT;
	}
	;

ListaId
	: ListaId ',' TID
	{
		$$.listaId = insLista(&$1, $3.id);
	}
	| TID
	{
		$$.listaId = criarLista($1.id);
	}
	;

Bloco
	: '{'ListaCmd'}'
	{
		$$.ptr = $2.ptr;
	}
	;

ListaCmd
	: ListaCmd Comando
	{
		$$.ptr = criarNoAST(AST_LISTA, $1.ptr, $2.ptr);
	}
	| Comando
	{
		$$.ptr = criarNoAST(AST_LISTA, $1.ptr, NULL);
	}
	;

Comando
	: CmdSe
	{
		$$.ptr = $1.ptr;
	}
	| CmdEnquanto
	{
		$$.ptr = $1.ptr;
	}
	| CmdAtrib
	{
		$$.ptr = $1.ptr;
	}
	| CmdEscrita
	{
		$$.ptr = $1.ptr;
	}
	| CmdLeitura
	{
		$$.ptr = NULL;
	}
	| ChamadaProc
	{
		$$.ptr = NULL;
	}
	| Retorno
	{
		$$.ptr = NULL;
	}
	;

Retorno
	: TRETURN ExpressaoAritmetica';'
	| TRETURN TLITERAL';'
	;

CmdSe
	: TIF '('ExpressaoLogica')' Bloco
	{
		$$.ptr = criarNoIF($3.ptr, $5.ptr, NULL);
	}
	| TIF '('ExpressaoLogica')' Bloco TELSE Bloco
	{
		$$.ptr = criarNoIF($3.ptr, $5.ptr, $7.ptr);
	}
	;

CmdEnquanto
	: TWHILE '('ExpressaoLogica')' Bloco
	{
		$$.ptr = criarNoWhile($3.ptr, $5.ptr);
	}
	| TDO Bloco TWHILE '('ExpressaoLogica')' ';'
	{
		$$.ptr = criarNoDoWhile($5.ptr, $2.ptr);
	}
	;

CmdAtrib
	: TID '=' ExpressaoAritmetica';'
	{
		$1.ptr = criarFolhaID(AST_VAR, $1.id);
		$1.tipo = consultaTipo($1.id);
		if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoAST(AST_ATRIB, $1.ptr, f2iAST($3.ptr));
			addError(ERR_1, linha);
		}
		else if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoAST(AST_ATRIB, $1.ptr, i2fAST($3.ptr));
			addError(ERR_1, linha);
		}
		else {
			$$.ptr = criarNoAST(AST_ATRIB, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
	| TID '=' TLITERAL ';'
	{
		$1.ptr = criarFolhaID(AST_VAR, $1.id);
		$1.tipo = consultaTipo($1.id);
		if ($1.tipo != T_STR)
		{
			addError(ERR_4, linha);
			YYABORT;
		}
		$3.ptr = criarFolhaLiteral($3.text);
		$$.ptr = criarNoAST(AST_ATRIB, $1.ptr, $3.ptr);
	}
	| AutoOperacao ';'
	{
		$$.ptr = $1.ptr;
	}
	;

CmdEscrita
	: TPRINT '(' ExpressaoAritmetica ')'';'
	{
		$$.ptr = criarNoAST(AST_PRINT, $3.ptr, NULL);
	}
	| TPRINT '(' TLITERAL ')'';'
	{
		$3.ptr = criarFolhaLiteral($3.text);
		$$.ptr = criarNoAST(AST_PRINT, $3.ptr, NULL);
	}
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
	{
		if ($1.tipo == T_STR || $3.tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoRel(AST_REL_LT, i2fAST($1.ptr), $3.ptr);
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoRel(AST_REL_LT, $1.ptr, i2fAST($3.ptr));
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			$$.ptr = criarNoRel(AST_REL_LT, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
	| ExpressaoAritmetica '>' ExpressaoAritmetica
	{
		if ($1.tipo == T_STR || $3.tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoRel(AST_REL_GT, i2fAST($1.ptr), $3.ptr);
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoRel(AST_REL_GT, $1.ptr, i2fAST($3.ptr));
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			$$.ptr = criarNoRel(AST_REL_GT, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
	| ExpressaoAritmetica TMEIG ExpressaoAritmetica
	{
		if ($1.tipo == T_STR || $3.tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoRel(AST_REL_LE, i2fAST($1.ptr), $3.ptr);
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoRel(AST_REL_LE, $1.ptr, i2fAST($3.ptr));
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			$$.ptr = criarNoRel(AST_REL_LE, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
	| ExpressaoAritmetica TMAIG ExpressaoAritmetica
	{
		if ($1.tipo == T_STR || $3.tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoRel(AST_REL_GE, i2fAST($1.ptr), $3.ptr);
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoRel(AST_REL_GE, $1.ptr, i2fAST($3.ptr));
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			$$.ptr = criarNoRel(AST_REL_GE, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
	| ExpressaoAritmetica TEQ ExpressaoAritmetica
	{
		if ($1.tipo == T_STR || $3.tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoRel(AST_REL_EQ, i2fAST($1.ptr), $3.ptr);
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoRel(AST_REL_EQ, $1.ptr, i2fAST($3.ptr));
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			$$.ptr = criarNoRel(AST_REL_EQ, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
	| ExpressaoAritmetica TDIF ExpressaoAritmetica
	{
		if ($1.tipo == T_STR || $3.tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoRel(AST_REL_NE, i2fAST($1.ptr), $3.ptr);
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoRel(AST_REL_NE, $1.ptr, i2fAST($3.ptr));
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			$$.ptr = criarNoRel(AST_REL_NE, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
	;

ExpressaoLogica
	: ExpressaoLogica TAND ArgumentoLogico
	{
		$$.ptr = criarNoAST(AST_LOG_AND, $1.ptr, $3.ptr);
	}
	| ExpressaoLogica TOR ArgumentoLogico
	{
		$$.ptr = criarNoAST(AST_LOG_OR, $1.ptr, $3.ptr);
	}
	| ArgumentoLogico
	{
		$$.ptr = $1.ptr;
	}
	;

ArgumentoLogico
	: '('ExpressaoLogica')'
	{
		$$.ptr = $2.ptr;
	}
	| '!' ArgumentoLogico
	{
		$$.ptr = criarNoAST(AST_LOG_NOT, $2.ptr, NULL);
	}
	| ExpressaoRelacional
	{
		$$.ptr = $1.ptr;
	}
  	;

ExpressaoAritmetica
	: ExpressaoAritmetica '+' TermoAritmetico
	{
		if ($1.tipo == T_STR || $3.tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoArit(AST_ARIT_ADD, i2fAST($1.ptr), $3.ptr);
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoArit(AST_ARIT_ADD, $1.ptr, i2fAST($3.ptr));
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			$$.ptr = criarNoArit(AST_ARIT_ADD, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
| ExpressaoAritmetica '-' TermoAritmetico
	{
		if ($1.tipo == T_STR || $3.tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoArit(AST_ARIT_SUB, i2fAST($1.ptr), $3.ptr);
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else
		if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoArit(AST_ARIT_SUB, $1.ptr, i2fAST($3.ptr));
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			$$.ptr = criarNoArit(AST_ARIT_SUB, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
	| TermoAritmetico
	{
		$$.ptr = $1.ptr;
	}
	;

TermoAritmetico
	: TermoAritmetico '*' FatorAritmetico
	{
		if ($1.tipo == T_STR || $3.tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoArit(AST_ARIT_MUL, i2fAST($1.ptr), $3.ptr);
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoArit(AST_ARIT_MUL, $1.ptr, i2fAST($3.ptr));
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			$$.ptr = criarNoArit(AST_ARIT_MUL, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
	| TermoAritmetico '/' FatorAritmetico
	{
		if ($1.tipo == T_STR || $3.tipo == T_STR) {
			addError(ERR_2, linha);
			YYABORT;
		}
		else if ($1.tipo == T_INT && $3.tipo == T_FLT) {
			$$.ptr = criarNoArit(AST_ARIT_DIV, i2fAST($1.ptr), $3.ptr);
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else if ($1.tipo == T_FLT && $3.tipo == T_INT) {
			$$.ptr = criarNoArit(AST_ARIT_DIV, $1.ptr, i2fAST($3.ptr));
			$$.tipo = T_FLT;
			addError(ERR_0, linha);
		}
		else {
			$$.ptr = criarNoArit(AST_ARIT_DIV, $1.ptr, $3.ptr);
			$$.tipo = $1.tipo;
		}
	}
	| FatorAritmetico
	{
		$$.ptr = $1.ptr;
		$$.tipo = $1.tipo;
	}
	;

FatorAritmetico
	: '('ExpressaoAritmetica')'
	{
		$$.tipo = $2.tipo;
		$$.ptr = $2.ptr;
	}
	| '-' FatorAritmetico
	{
		$$.tipo = $2.tipo;
		$$.ptr = criarNoAST(AST_NEG, $2.ptr, NULL);
	}
	| ChamadaFuncao
	{
		$$.ptr = criarFolhaID(AST_FUNCAO, $1.id);
	}
	| TINT
	{
		$$.tipo = T_INT;
		$$.ptr = criarFolhaInt($1.ival);
	}
	| TFLOAT
	{
		$$.tipo = T_FLT;
		$$.ptr = criarFolhaFloat($1.fval);
	}
	| TID
	{
		$$.ptr = criarFolhaID(AST_VAR, $1.id);
		$$.tipo = consultaTipo($1.id);
		if ($$.tipo == T_NEX)
		{
			addError(ERR_3, linha);
			YYABORT;
		}
	}
	;

AutoOperacao
	: TID '+''+'
	{
		$1.ptr = criarFolhaID(AST_VAR, $1.id);
		$$.tipo = consultaTipo($1.id);
		if ($$.tipo == T_FLT)
			$$.ptr = criarNoAuto(AST_AUTO_ADD, $1.ptr, i2fAST(criarFolhaInt(1)));
		else
			$$.ptr = criarNoAuto(AST_AUTO_ADD, $1.ptr, criarFolhaInt(1));
	}
	| TID '+''=' ExpressaoAritmetica
	{
		$1.ptr = criarFolhaID(AST_VAR, $1.id);
		$$.tipo = consultaTipo($1.id);
		if ($$.tipo == T_FLT)
			if ($4.tipo == T_INT)
				$$.ptr = criarNoAuto(AST_AUTO_ADD, $1.ptr, i2fAST($4.ptr));
			else
				$$.ptr = criarNoAuto(AST_AUTO_ADD, $1.ptr, $4.ptr);
		else
			if ($4.tipo == T_INT)
				$$.ptr = criarNoAuto(AST_AUTO_ADD, $1.ptr, $4.ptr);
			else
				$$.ptr = criarNoAuto(AST_AUTO_ADD, $1.ptr, f2iAST($4.ptr));
	}
	| TID '-''-'
	{
		$1.ptr = criarFolhaID(AST_VAR, $1.id);
		$$.tipo = consultaTipo($1.id);
		if ($$.tipo == T_FLT)
			$$.ptr = criarNoAuto(AST_AUTO_SUB, $1.ptr, i2fAST(criarFolhaInt(1)));
		else
			$$.ptr = criarNoAuto(AST_AUTO_SUB, $1.ptr, criarFolhaInt(1));
	}
	| TID '-''=' ExpressaoAritmetica
	{
		$1.ptr = criarFolhaID(AST_VAR, $1.id);
		$$.tipo = consultaTipo($1.id);
		if ($$.tipo == T_FLT)
			if ($4.tipo == T_INT)
				$$.ptr = criarNoAuto(AST_AUTO_SUB, $1.ptr, i2fAST($4.ptr));
			else
				$$.ptr = criarNoAuto(AST_AUTO_SUB, $1.ptr, $4.ptr);
		else
			if ($4.tipo == T_INT)
				$$.ptr = criarNoAuto(AST_AUTO_SUB, $1.ptr, $4.ptr);
			else
				$$.ptr = criarNoAuto(AST_AUTO_SUB, $1.ptr, f2iAST($4.ptr));
	}
	| TID '*''=' ExpressaoAritmetica
	{
		$1.ptr = criarFolhaID(AST_VAR, $1.id);
		$$.tipo = consultaTipo($1.id);
		if ($$.tipo == T_FLT)
			if ($4.tipo == T_INT)
				$$.ptr = criarNoAuto(AST_AUTO_MUL, $1.ptr, i2fAST($4.ptr));
			else
				$$.ptr = criarNoAuto(AST_AUTO_MUL, $1.ptr, $4.ptr);
		else
			if ($4.tipo == T_INT)
				$$.ptr = criarNoAuto(AST_AUTO_MUL, $1.ptr, $4.ptr);
			else
				$$.ptr = criarNoAuto(AST_AUTO_MUL, $1.ptr, f2iAST($4.ptr));
	}
	| TID '/''=' ExpressaoAritmetica
	{
		$1.ptr = criarFolhaID(AST_VAR, $1.id);
		$$.tipo = consultaTipo($1.id);
		if ($$.tipo == T_FLT)
			if ($4.tipo == T_INT)
				$$.ptr = criarNoAuto(AST_AUTO_DIV, $1.ptr, i2fAST($4.ptr));
			else
				$$.ptr = criarNoAuto(AST_AUTO_DIV, $1.ptr, $4.ptr);
		else
			if ($4.tipo == T_INT)
				$$.ptr = criarNoAuto(AST_AUTO_DIV, $1.ptr, $4.ptr);
			else
				$$.ptr = criarNoAuto(AST_AUTO_DIV, $1.ptr, f2iAST($4.ptr));
	}
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
