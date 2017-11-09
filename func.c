#include "func.h"

extern struct Simbolo *tabSim;

// CRIA LISTA DE ID AQUI
struct ListaId* criarLista(char *id)
{
	struct ListaId *ret;
	ret = malloc(sizeof(struct ListaId));
	if (!ret)
	{
		perror("Erro em criarLista, malloc ret: ");
		exit(EXIT_FAILURE);
	}

	ret->prox = NULL;
	strncpy(ret->id, id, MAX_ID_LEN - 1);

	return ret;
}

// INSERE NA LISTA DE ID AQUI
struct ListaId* insLista(struct Atributo *atr, char *id)
{
	struct ListaId *aux = atr->listaId, *novo = NULL;

	novo = malloc(sizeof(struct ListaId));
	if (!novo)
	{
		perror("Erro em insLista, malloc novo: ");
		exit(EXIT_FAILURE);
	}

	strncpy(novo->id, id, MAX_ID_LEN - 1);
	novo->prox = aux;

	return novo;
}

// INSERE NA TABELA DE SÍMBOLOS AQUI
void insTabSim(int tipo, struct ListaId *lista)
{
	struct Simbolo *noTabSim = tabSim, *novoSimbolo = NULL;

	// Criar primeiro raiz da árvore
	/*
	if (noTabSim == NULL)
	{
		noTabSim = malloc(sizeof(struct Simbolo));
		if (!noTabSim)
		{
			perror("Erro em insTabSim, malloc tabSim: ");
			exit(EXIT_FAILURE);
		}
	}*/
	// FIM

	int direcao = -1;
	struct ListaId *lista_aux = lista, *lista_aux2 = NULL;
	while (lista_aux != NULL)
	{
		noTabSim = tabSim;
		direcao = -1;
		while (noTabSim != NULL)
		{
			if (strcmp(lista_aux->id, noTabSim->id) < 0) {
				if (noTabSim->esq != NULL)
					noTabSim = noTabSim->esq;
				else
				{
					direcao = 0; // ESQUERDA
					break;
				}
			} else {
				if (noTabSim->dir != NULL)
					noTabSim = noTabSim->dir;
				else
				{
					direcao = 1; // DIREITA
					break;
				}
			}
		}

		novoSimbolo = malloc(sizeof(struct Simbolo));
		if (!novoSimbolo)
		{
			perror("Erro: [insTabSim] - malloc novoSimbolo: ");
			exit(EXIT_FAILURE);
		}

		novoSimbolo->tipo = tipo;
		strncpy(novoSimbolo->id, lista_aux->id, MAX_ID_LEN - 1);
		novoSimbolo->esq = NULL; novoSimbolo->dir = NULL;

		if (noTabSim == NULL)
		{
			tabSim = novoSimbolo;
			noTabSim = tabSim;
		}
		else
		{
			if (direcao == 0)
			{
				noTabSim->esq = novoSimbolo;
			}
			else
			{
				noTabSim->dir = novoSimbolo;
			}
		}

		lista_aux = lista_aux->prox;
	}

	freeLista(lista);
}

void freeLista(struct ListaId *lista)
{
	struct ListaId *aux = lista, *aux2 = NULL;
	while (aux != NULL)
	{
		aux2 = aux;
		aux = aux->prox;
		free(aux2);
		aux2 = NULL;
	}
	aux = NULL;
}

void printTabSim(struct Simbolo *tabSim)
{
	if (tabSim != NULL)
	{
		printTabSim(tabSim->dir);
		printTabSim(tabSim->esq);

		char tipo[20];

		switch(tabSim->tipo)
		{
			case T_INT: strcpy(tipo, "int"); break;
			case T_FLT: strcpy(tipo, "float"); break;
			case T_STR: strcpy(tipo, "string"); break;
			default: strcpy(tipo, "nimplementado"); break;
		}

		printf("%-10s | %s\n", tabSim->id, tipo);
	}
}


// Impressão pós-ordem
void imprimePosOrdem(struct AST * raiz)
{
	switch (raiz->cod)
	{
		case ADD:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			printf("iadd");
			break;

		case SUB:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			printf("isub");
			break;

		case MUL:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			printf("imul");
			break;

		case DIV:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			printf("idiv");
			break;

		case CONSTINT:
			if (raiz->constInt == -1) printf("iconst_m1");
			else if (raiz->constInt > -1 && raiz->constInt <= 5) printf("iconst_%d", raiz->constInt);
			else if (raiz->constInt > -128 && raiz->constInt < 128) printf("bipush %d", raiz->constInt);
			else printf("not-implemented (constint > 128)");
			break;

		case CONSTFLOAT:
			//printf("%f ", raiz->constFloat);
			printf("not-implemented (constfloat)");
			break;

		case VAR:
			printf("iload <%s>", raiz->id);
			break;

		case FUNCAO:
			printf("not-implemented (funcao)", raiz->id);
			break;

		case ATRIB:
			//imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			printf("istore <%s>", raiz->esq->id);
			break;

		case NEG:
			imprimePosOrdem(raiz->esq);
			printf("ineg");
			break;

		default:
			break;
	}

	free(raiz);
	raiz = NULL;
	printf("\n");
}

// FAZER ISSO v
struct AST * criarFolhaID(int tipo, char *nome)
{
	struct AST * folha = malloc(sizeof(struct AST));
	if (folha == NULL)
	{
		perror("Erro: [criarFolhaID] - malloc(struct AST): ");
		exit(EXIT_FAILURE);
	}

	folha->cod		= tipo;
	strncpy(folha->id, nome, MAX_ID_LEN);

	return folha;
}

// FAZER ISSO v
struct AST * criarFolhaInt(int tipo, int value)
{
	struct AST * folha = malloc(sizeof(struct AST));
	if (folha == NULL)
	{
		perror("Erro: [criarFolhaInt] - malloc(struct AST): ");
		exit(EXIT_FAILURE);
	}

	folha->cod 		= tipo;
	folha->constInt = value;

	return folha;
}

// FAZER ISSO v
struct AST * criarFolhaFloat(int tipo, float value)
{
	struct AST * folha = malloc(sizeof(struct AST));
	if (folha == NULL)
	{
		perror("Erro: [criarFolhaFloat] - malloc(struct AST): ");
		exit(EXIT_FAILURE);
	}

	folha->cod 		  = tipo;
	folha->constFloat = value;

	return folha;
}

struct AST * criarNoAST(int tipo, struct AST * esq, struct AST * dir)
{
	struct AST * no = malloc(sizeof(struct AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoAST] - malloc(struct AST): ");
		exit(EXIT_FAILURE);
	}

	no->cod = tipo;
	no->esq = esq;
	no->dir = dir;

	return no;
}