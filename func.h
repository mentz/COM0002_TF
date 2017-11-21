#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ID_LEN 11

enum 
{
	T_NEX, T_INT, T_STR, T_FLT
};

enum AST_TYPES
{
	AST_MUL, AST_DIV, AST_ADD, AST_SUB,
	AST_CONSTINT, AST_CONSTFLOAT, AST_VAR, AST_FUNCAO,
	AST_LISTA, AST_ATRIB, AST_NEG, AST_I2F, AST_F2I, AST_IF,
	AST_LOG_AND, AST_LOG_OR, AST_LOG_NOT,
	AST_REL_DIF, AST_REL_EQ, AST_REL_MEN, AST_REL_MAI, AST_REL_MEIG, AST_REL_MAIG
};

enum
{
	ERR_0, 		// Aritmética com tipos diferentes (1.5 + 1)
	ERR_1, 		// Atribuição de tipo diferente (int a = 1.2;)
	ERR_2,		// Aritmética com string (1.5 * 5 + a * "oi mundo")
	ERR_3		// Variável inexistente com o ID informado
};

struct CompErrors
{
	int errorCode;
	int line;
	struct CompErrors *next;
};

struct ListaId
{
	char id[MAX_ID_LEN];
	struct ListaId *prox;
};

struct Atributo
{
	int tipo;
	struct ListaId *listaId;
	char id[MAX_ID_LEN];
	struct AST *ptr;
	int ival;
	float fval;
	
	// int neg;
};

struct Simbolo
{
	char id[MAX_ID_LEN];
	int tipo;
	int frame;
	struct Simbolo *esq, *dir;
};

struct AST
{
	int cod;
	int tipo;
	char id[MAX_ID_LEN];
	struct AST *esq, *dir;
	struct AST *cond, *pthen, *pelse;
	int constInt;
	float constFloat;
	int labelTrue;
	int labelFalse;
	int labelNext;
};


void addError(int error, int line);
void printErrors();

struct ListaId* criarLista(char *id);
struct ListaId* insLista(struct Atributo *atr, char *id);
void insTabSim(int tipo, struct ListaId *lista);
int consultaTipo(char *id);
int consultaFrame(char *id);
void freeLista(struct ListaId *lista);
void printTabSim(struct Simbolo *tabSim);
void imprimePosOrdem(struct AST *raiz);
struct AST * criarFolhaID(int tipo, char *nome);
struct AST * criarFolhaInt(int value);
struct AST * criarFolhaFloat(float value);
struct AST * criarNoAST(int tipo, struct AST *esq, struct AST *dir);
struct AST * i2fAST(struct AST * iptr);
struct AST * f2iAST(struct AST * iptr);
struct AST * criarNoIF(struct AST * cond, struct AST * b1, struct AST * b2);
