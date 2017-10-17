#include "func.h"

// CRIA LISTA DE ID AQUI
struct ListaId criarLista(char[MAX_ID_LEN] id)
{
	struct ListaId ret;
	ret.prox = NULL;
	strncpy(ret.id, id, MAX_ID_LEN);

	return ret;
}

// INSERE NA LISTA DE ID AQUI
void insLista(struct ListaId lista, char[MAX_ID_LEN] id)
{
	// TODO
}

// INSERE NA TABELA DE SÍMBOLOS AQUI
// TODO