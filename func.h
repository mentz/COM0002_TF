#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ID_LEN 11
#define MAX_TEXT_LEN 2048

enum
{
	T_NEX, T_INT, T_STR, T_FLT
};

enum AST_TYPES
{
	AST_ARIT_ADD, AST_ARIT_SUB, AST_ARIT_MUL, AST_ARIT_DIV,
	AST_CONSTINT, AST_CONSTFLOAT, AST_LITERAL, AST_VAR, AST_FUNCAO,
	AST_LISTA, AST_ATRIB, AST_NEG, AST_I2F, AST_F2I,
	AST_IF, AST_WHILE, AST_DOWHILE,
	AST_LOG_AND, AST_LOG_OR, AST_LOG_NOT,
	AST_REL_EQ, AST_REL_NE, AST_REL_LT, AST_REL_LE, AST_REL_GT, AST_REL_GE,
	AST_PRINT,
	AST_AUTO_ADD, AST_AUTO_SUB, AST_AUTO_MUL, AST_AUTO_DIV
};

enum ERR_CODES
{
	ERR_0, 		// Aritmética com tipos diferentes (1.5 + 1)
	ERR_1, 		// Atribuição de tipo diferente (int a = 1.2;)
	ERR_2,		// Aritmética com string (1.5 * 5 + a * "oi mundo")
	ERR_3,		// Variável inexistente com o ID informado
	ERR_4		// Atribuindo valor inválido a tipo string
};

typedef struct CompErrors
{
	int errorCode;
	int line;
	struct CompErrors *next;
} CompErrors;

typedef struct ListaId
{
	char id[MAX_ID_LEN];
	struct ListaId *prox;
} ListaId;

typedef struct Atributo
{
	int tipo;
	struct ListaId *listaId;
	char id[MAX_ID_LEN];
	struct AST *ptr;
	int ival;
	float fval;
	char text[MAX_TEXT_LEN];
} Atributo;

typedef struct Simbolo
{
	char id[MAX_ID_LEN];
	int tipo;
	int frame;
	struct Simbolo *esq, *dir;
} Simbolo;

typedef struct AST
{
	int cod;
	int tipo;
	char id[MAX_ID_LEN];
	char text[MAX_TEXT_LEN];
	struct AST *esq, *dir;
	struct AST *cond, *pthen, *pelse;
	int constInt;
	float constFloat;
} AST;


void addError(int error, int line);
void printErrors();

ListaId* criarLista(char *id);
ListaId* insLista(Atributo *atr, char *id);
void insTabSim(int tipo, ListaId *lista);
int consultaTipo(char *id);
int consultaFrame(char *id);
void printTabSim(Simbolo *tabSim);
void freeLista(ListaId *lista);
AST * criarFolhaID(int tipo, char *nome);
AST * criarFolhaInt(int value);
AST * criarFolhaFloat(float value);
AST * criarFolhaLiteral(char *text);
AST * criarNoAST(int tipo, AST *esq, AST *dir);
AST * criarNoArit(int op, AST *esq, AST *dir);
AST * criarNoRel(int op, AST * esq, AST * dir);
AST * i2fAST(AST * iptr);
AST * f2iAST(AST * iptr);
AST * criarNoIF(AST * cond, AST * b1, AST * b2);
AST * criarNoWhile(AST * cond, AST * b1);
AST * criarNoDoWhile(AST * cond, AST * b1);
AST * criarNoAuto(int tipo, AST * var, AST * incr);
void printInicioArquivo();
void printStrings();
void printFinalMain();
void printAST(AST *r);
void printLogRel(AST *r, int labelTrue, int labelFalse);