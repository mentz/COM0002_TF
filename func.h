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
	AST_ARIT,
	AST_CONSTINT, AST_CONSTFLOAT, AST_VAR, AST_FUNCAO,
	AST_LISTA, AST_ATRIB, AST_NEG, AST_I2F, AST_F2I, AST_IF,
	AST_LOG_AND, AST_LOG_OR, AST_LOG_NOT, AST_REL
};

enum ARIT_TYPES { ADD, SUB, MUL, DIV };
enum LOGREL_TYPES { EQ, NE, LT, LE, GT, GE };

enum ERR_CODES
{
	ERR_0, 		// Aritmética com tipos diferentes (1.5 + 1)
	ERR_1, 		// Atribuição de tipo diferente (int a = 1.2;)
	ERR_2,		// Aritmética com string (1.5 * 5 + a * "oi mundo")
	ERR_3		// Variável inexistente com o ID informado
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
	int op;
	char id[MAX_ID_LEN];
	union {
		struct {
			struct AST *esq, *dir;
		};
		struct {
			struct AST *cond, *pthen, *pelse;
		};
	};
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
void freeLista(ListaId *lista);
void printTabSim(Simbolo *tabSim);
void printAST(AST *r);
void printLogRel(AST *r, int labelTrue, int labelFalse);
AST * criarFolhaID(int tipo, char *nome);
AST * criarFolhaInt(int value);
AST * criarFolhaFloat(float value);
AST * criarNoAST(int tipo, AST *esq, AST *dir);
AST * criarNoArit(int op, AST *esq, AST *dir);
AST * criarNoRel(int op, AST * esq, AST * dir);
AST * i2fAST(AST * iptr);
AST * f2iAST(AST * iptr);
AST * criarNoIF(AST * cond, AST * b1, AST * b2);
