#include "func.h"

extern struct CompErrors *err;
extern struct Simbolo *tabSim;
extern int frameNumber;
extern int labelCounter;

void addError(int error, int line)
{
	struct CompErrors *aux = err, *aux2;
	
	while (aux != NULL)
	{
		aux2 = aux;
		aux  = aux->next;
	}

	aux = malloc(sizeof(struct CompErrors));
	if (aux == NULL)
	{
		perror("Erro: addError Malloc");
		exit(EXIT_FAILURE);
	}

	if (err == NULL) err = aux;

	aux2->next     = aux;
	aux->errorCode = error;
	aux->line      = line;
	aux->next      = NULL;
}

void printErrors()
{
	struct CompErrors *aux = err;
	int i = 0;
	while (aux != NULL)
	{
		if (i == 0) printf("Problemas na compilação:\n");
		printf("#%d ", ++i);
		switch (aux->errorCode)
		{
			case ERR_0:
				printf("- Linha %d - Warn: aritmética com operandos de tipos diferentes (não fatal).", aux->line);
				break;

			case ERR_1:
				printf("- Linha %d - Warn: atribuição de tipo diferente (não fatal).", aux->line);
				break;

			case ERR_2:
				printf("- Linha %d - Erro: aritmética com string (fatal).", aux->line);
				break;

			case ERR_3:
				printf("- Linha %d - Erro: variável inexistente (fatal).", aux->line);
				break;

			default:
				printf(" - Erro desconhecido.");
				break;
		}
		printf("\n");

		aux = aux->next;
	}
}

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

		novoSimbolo->frame = frameNumber++;

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


/*-----------------------------------*/
int consultaTipo(char *id)
{
	struct Simbolo * aux = tabSim, *aux2;
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

	return T_NEX;
}


/*-----------------------------------*/
int consultaFrame(char *id)
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
			return aux->frame;
		}
	}

	return T_NEX;
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

		printf("%-10s | %5d | %s\n", tabSim->id, tabSim->frame, tipo);
	}
}

// AST
struct AST * criarFolhaID(int cod, char *nome)
{
	struct AST * folha = malloc(sizeof(struct AST));
	if (folha == NULL)
	{
		perror("Erro: [criarFolhaID] - malloc(struct AST): ");
		exit(EXIT_FAILURE);
	}

	folha->cod		= cod;
	folha->tipo		= consultaTipo(nome);
	strncpy(folha->id, nome, MAX_ID_LEN);

	return folha;
}

// AST
struct AST * criarFolhaInt(int value)
{
	struct AST * folha = malloc(sizeof(struct AST));
	if (folha == NULL)
	{
		perror("Erro: [criarFolhaInt] - malloc(struct AST): ");
		exit(EXIT_FAILURE);
	}

	folha->cod 		= AST_CONSTINT;
	folha->tipo		= T_INT;
	folha->constInt = value;

	return folha;
}

// AST
struct AST * criarFolhaFloat(float value)
{
	struct AST * folha = malloc(sizeof(struct AST));
	if (folha == NULL)
	{
		perror("Erro: [criarFolhaFloat] - malloc(struct AST): ");
		exit(EXIT_FAILURE);
	}

	folha->cod 		  = AST_CONSTFLOAT;
	folha->tipo		  = T_FLT;
	folha->constFloat = value;

	return folha;
}

// AST
struct AST * criarNoAST(int cod, struct AST * esq, struct AST * dir)
{
	struct AST * no = malloc(sizeof(struct AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoAST] - malloc(struct AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = cod;
	no->esq  = esq;
	no->dir  = dir;
	if (cod != AST_LISTA)
		no->tipo = esq->tipo;

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

	no->cod  = AST_I2F;
	no->tipo = T_FLT;
	no->esq  = iptr;

	return no;
}

// Cria um nó Float2Int, retorna seu endereço e aponta para iptr;
struct AST * f2iAST(struct AST * iptr) {
	struct AST * no = malloc(sizeof(struct AST));
	if (no == NULL)
	{
		perror("Erro: [f2iAST] - malloc(struct AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = AST_F2I;
	no->tipo = T_FLT;
	no->esq  = iptr;

	return no;
}

// Cria um nó IF, retorna seu endereço;
struct AST * criarNoIF(struct AST * cond, struct AST * b1, struct AST * b2)
{
	struct AST * no = malloc(sizeof(struct AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoIF] - malloc(struct AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = AST_IF;
	no->cond = cond;
	no->esq  = b1;
	no->dir  = b2;

	return no;
}

// Impressão pós-ordem
void imprimePosOrdem(struct AST * raiz)
{
	switch (raiz->cod)
	{
		/*
		AST_REL_MEN, AST_REL_MAI, AST_REL_MEIG, AST_REL_MAIG, AST_REL_EQ, AST_REL_DIF,
		AST_LOG_AND, AST_LOG_OR, AST_LOG_NOT
		*/
		case AST_ADD:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			printf("AST_ADD: ");
			if (raiz->tipo == T_INT) printf("iadd");
			else if (raiz->tipo == T_FLT) printf("fadd");
			else printf("<ADD>");
			break;

		case AST_SUB:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			printf("AST_SUB: ");
			if (raiz->tipo == T_INT) printf("isub");
			else if (raiz->tipo == T_FLT) printf("fsub");
			else printf("<SUB>");
			break;

		case AST_MUL:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			printf("AST_MUL: ");
			if (raiz->tipo == T_INT) printf("imul");
			else if (raiz->tipo == T_FLT) printf("fmul");
			else printf("<MUL>");
			break;

		case AST_DIV:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			printf("AST_DIV: ");
			if (raiz->tipo == T_INT) printf("idiv");
			else if (raiz->tipo == T_FLT) printf("fdiv");
			else printf("<DIV>");
			break;

		case AST_CONSTINT:
			printf("AST_CONSTINT: ");
			if (raiz->constInt == -1) printf("iconst_m1");
			else if (raiz->constInt > -1 && raiz->constInt <= 5) printf("iconst_%d", raiz->constInt);
			else if (raiz->constInt > -128 && raiz->constInt < 128) printf("bipush %d", raiz->constInt);
			else printf("ldc %d", raiz->constInt);
			break;

		case AST_CONSTFLOAT:
			printf("AST_CONSTFLOAT: ");
			printf("ldc %f", raiz->constFloat);
			break;

		case AST_VAR:
			printf("AST_VAR: ");
			if (raiz->tipo == T_INT) printf("iload %d", consultaFrame(raiz->id));
			else if (raiz->tipo == T_FLT) printf("fload %d", consultaFrame(raiz->id));
			else printf("<VAR>");
			break;

		case AST_FUNCAO:
			printf("AST_FUNCAO: ");
			printf("unimplemented: funcao", raiz->id);
			break;

		case AST_LISTA:
			printf("AST_LISTA: \n");
			imprimePosOrdem(raiz->esq);
			if (raiz->dir != NULL) imprimePosOrdem(raiz->dir);
			break;

		case AST_ATRIB:
			imprimePosOrdem(raiz->dir);
			printf("AST_ATRIB: ");
			if (raiz->tipo == T_INT) printf("istore %d", consultaFrame(raiz->esq->id));
			else if (raiz->tipo == T_FLT) printf("fstore %d", consultaFrame(raiz->esq->id));
			else printf("<ATRIB>");
			break;

		case AST_NEG:
			imprimePosOrdem(raiz->esq);
			printf("AST_NEG: ");
			if (raiz->tipo == T_INT) printf("ineg");
			else if (raiz->tipo == T_FLT) printf("fneg");
			else printf("<NEG>");
			break;

		case AST_I2F:
			imprimePosOrdem(raiz->esq);
			printf("AST_I2F: ");
			printf("i2f");
			break;
			
		case AST_F2I:
			imprimePosOrdem(raiz->esq);
			printf("AST_F2I: ");
			printf("f2i");
			break;

		case AST_IF:
		printf("EU TO AQUI CARIA;\n");
			raiz->labelTrue        = labelCounter++;
			raiz->labelFalse       = labelCounter++;
			raiz->cond->labelTrue  = raiz->labelTrue;
			raiz->cond->labelFalse = raiz->labelFalse;
			imprimePosOrdem(raiz->cond);
			printf("AST_IF: ");
			//if (raiz->cond->cod != AST_LOG_AND || raiz->cond->cod != AST_LOG_OR)
				printf("goto L%d", raiz->labelFalse);
			break;

		case AST_REL_DIF:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			if (raiz->tipo == T_INT) printf("if_icmp");
			else if (raiz->tipo == T_FLT) printf("unimplemented <fcmp>");
			printf("ne L%d", raiz->labelTrue);
			break;

		case AST_REL_EQ:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			if (raiz->tipo == T_INT) printf("if_icmp");
			else if (raiz->tipo == T_FLT) printf("unimplemented <fcmp>");
			printf("eq L%d", raiz->labelTrue);
			break;

		case AST_REL_MEN:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			if (raiz->tipo == T_INT) printf("if_icmp");
			else if (raiz->tipo == T_FLT) printf("unimplemented <fcmp>");
			printf("lt L%d", raiz->labelTrue);
			break;

		case AST_REL_MEIG:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			if (raiz->tipo == T_INT) printf("if_icmp");
			else if (raiz->tipo == T_FLT) printf("unimplemented <fcmp>");
			printf("le L%d", raiz->labelTrue);
			break;

		case AST_REL_MAI:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			if (raiz->tipo == T_INT) printf("if_icmp");
			else if (raiz->tipo == T_FLT) printf("unimplemented <fcmp>");
			printf("gt L%d", raiz->labelTrue);
			break;

		case AST_REL_MAIG:
			imprimePosOrdem(raiz->esq);
			imprimePosOrdem(raiz->dir);
			if (raiz->tipo == T_INT) printf("if_icmp");
			else if (raiz->tipo == T_FLT) printf("unimplemented <fcmp>");
			printf("ge L%d", raiz->labelTrue);
			break;

		default:
			printf("unimplemented: %d", raiz->cod);
			break;
	}

	free(raiz);
	raiz = NULL;
	printf("\n");
}