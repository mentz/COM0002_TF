#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID_LEN 11

enum {T_INT, T_STR, T_FLT};

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
};

struct Simbolo
{
	char id[MAX_ID_LEN];
	int tipo;
	struct Simbolo *esq, *dir;
};

struct ListaId* criarLista(char *id);

struct ListaId* insLista(struct Atributo *atr, char *id);

void insTabSim(int tipo, struct ListaId *lista);

void freeLista(struct ListaId *lista);

void printTabSim(struct Simbolo *tabSim);
