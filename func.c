#include "func.h"

// CRIA LISTA DE ID AQUI
struct ListaId criarLista(char id[MAX_ID_LEN])
{
	struct ListaId ret;
	ret.prox = NULL;
	strncpy(ret.id, id, MAX_ID_LEN);

	return ret;
}

// INSERE NA LISTA DE ID AQUI
void insLista(struct ListaId lista, char id[MAX_ID_LEN])
{
	// TODO
}

// INSERE NA TABELA DE SÍMBOLOS AQUI
void insTabSim(struct Simbolo *tb, struct Atributo atributos)
{
	struct Simbolo *aux = tb;
	if (aux == NULL)
	{
		aux = malloc(sizeof(struct Simbolo));
		if (!aux)
		{
			perror("Erro em insTabSim, malloc: ");
			exit(EXIT_FAILURE);
		}

		atributos.listaId[0];asda
	}
}