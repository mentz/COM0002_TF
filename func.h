#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID_LEN 11

enum {T_INT, T_STR, T_FLT};
enum {MUL, DIV, ADD, SUB, CONSTINT, CONSTFLOAT, VAR, FUNCAO, NEG};

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
	struct Simbolo *esq, *dir;
};

struct AST
{
	int cod;
	char id[MAX_ID_LEN];
	struct AST *esq, *dir;
	int constInt;
	float constFloat;
	// int neg;
};

struct ListaId* criarLista(char *id);

struct ListaId* insLista(struct Atributo *atr, char *id);

void insTabSim(int tipo, struct ListaId *lista);

void freeLista(struct ListaId *lista);

void printTabSim(struct Simbolo *tabSim);

void imprimePosOrdem(struct AST *raiz);
struct AST * criarFolhaID(int tipo, char *nome);
struct AST * criarFolhaInt(int tipo, int value);
struct AST * criarFolhaFloat(int tipo, float value);
struct AST * criarNoAST(int tipo, struct AST *esq, struct AST *dir);
