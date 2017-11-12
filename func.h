#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ID_LEN 11

enum
{
	NAOEXISTE, T_INT, T_STR, T_FLT
};

enum
{
	MUL, DIV, ADD, SUB, CONSTINT, CONSTFLOAT, VAR, FUNCAO, ATRIB, NEG, I2F, F2I
};

enum
{
	ERR_0, 		// Atribuição de tipo diferente (int a = 1.2;)
	ERR_1, 		// Aritmética com tipos diferentes (1.5 + 1)
	ERR_2		// Aritmética com string (1.5 * 5 + a * "oi mundo")
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
	int constInt;
	float constFloat;
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
struct AST * criarFolhaInt(int tipo, int value);
struct AST * criarFolhaFloat(int tipo, float value);
struct AST * criarNoAST(int tipo, struct AST *esq, struct AST *dir);
struct AST * i2fAST(struct AST * iptr);
struct AST * f2iAST(struct AST * iptr);
