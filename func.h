#include <stdio.h>
#include <stdlib.h>

#define MAX_ID_LEN 11

struct ListaId
{
	char id[MAX_ID_LEN];
	struct ListaId *prox;
};

struct Atributo
{
	int tipo;
	struct ListaId listaId;
	char id[MAX_ID_LEN];
};

enum {T_INT, T_STR, T_FLT};

struct Simbolo
{
	char id[MAX_ID_LEN];
	int tipo;
	struct Simbolo *esq, *dir;
};

struct ListaId criarLista(char id[MAX_ID_LEN]);

void insLista(struct ListaId lista, char id[MAX_ID_LEN]);

void insTabSim(struct Atributo atributos);

void printTabSim();