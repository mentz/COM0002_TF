#include "func.h"

extern struct Simbolo *tabSim;
extern int frameNumber;

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
			novoSimbolo->frame = frameNumber++;
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

int consultaTipo(char *id)
{
	struct Simbolo * aux = tabSim;
	// Encontrar tipo da variável na tabela de símbolos.
	while (aux != NULL)
	{
		if (strcmp(id, aux->id) < 0)
		{
			aux = aux->esq;
			continue;
		} else if (strcmp(id, aux->id) > 0)
		{
			aux = aux->dir;
			continue;
		} else
		{
			return aux->tipo;
		}
	}

	return NAOEXISTE;
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

		printf("%-10s | %d | %s\n", tabSim->id, tabSim->frame, tipo);
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
			if (raiz->cod == CONSTINT) printf("iadd");
			else if (raiz->cod == CONSTFLOAT) printf("fadd");
			break;

		case SUB:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			if (raiz->cod == CONSTINT) printf("isub");
			else if (raiz->cod == CONSTFLOAT) printf("fsub");
			break;

		case MUL:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			if (raiz->cod == CONSTINT) printf("imul");
			else if (raiz->cod == CONSTFLOAT) printf("fmul");
			break;

		case DIV:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			if (raiz->cod == CONSTINT) printf("idiv");
			else if (raiz->cod == CONSTFLOAT) printf("fdiv");
			break;

		case CONSTINT:
			if (raiz->constInt == -1) printf("iconst_m1");
			else if (raiz->constInt > -1 && raiz->constInt <= 5) printf("iconst_%d", raiz->constInt);
			else if (raiz->constInt > -128 && raiz->constInt < 128) printf("bipush %d", raiz->constInt);
			else printf("ldc %d", raiz->constInt);
			break;

		case CONSTFLOAT:
			printf("ldc %f", raiz->constFloat);
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
		perror("Erro: [criarNoAST] - malloc(struct AST)");
		exit(EXIT_FAILURE);
	}

	no->cod = tipo;
	no->esq = esq;
	no->dir = dir;

	return no;
}

// Cria um nó Int2Float, retorna seu endereço e aponta para iptr;
struct AST * i2fAST(struct AST * iptr) {
	struct AST * no = malloc(sizeof(struct AST));
	if (no == NULL)
	{
		perror("Erro: [i2fAST] - malloc(struct AST)");
		exit(EXIT_FAILURE);
	}

	no->cod = CONV_I2F;
	no->esq = iptr;

	return no;
}