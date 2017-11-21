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

// No Aritmético
struct AST * criarNoArit(int op, struct AST *esq, struct AST *dir)
{
	struct AST * no = malloc(sizeof(struct AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoArit] - malloc(struct AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = AST_ARIT;
	no->op   = op;
	no->esq  = esq;
	no->dir  = dir;
	if (cod != AST_LISTA)
		no->tipo = esq->tipo;

	return no;
}

// No Lógico-Relacional
struct AST * criarNoRel(int op, struct AST * esq, struct AST * dir)
{
	struct AST * no = malloc(sizeof(struct AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoRel] - malloc(struct AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = AST_REL;
	no->op   = op;
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
	no->pthen  = b1;
	no->pelse  = b2;

	return no;
}

// Impressão pós-ordem
void printAST(struct AST * r)
{
	int labelTrue, labelFalse, labelNext;
	switch (r->cod)
	{
		case AST_ARIT:
			printAST(r->esq);
			printAST(r->dir);
			printf("\t");
			if (r->tipo == T_INT)
			{
				switch (r->op)
				{
					case ADD: printf("iadd"); break;
					case SUB: printf("isub"); break;
					case MUL: printf("imul"); break;
					case DIV: printf("idiv"); break;
					default: printf("ERROR"); break;
				}
			}
			else if (r->tipo == T_FLT)
			{
				switch (r->op)
				{
					case ADD: printf("fadd"); break;
					case SUB: printf("fsub"); break;
					case MUL: printf("fmul"); break;
					case DIV: printf("fdiv"); break;
					default: printf("ERROR"); break;
				}
			}
			else printf("<ARIT TYPE ERROR>");
			printf("\n");
			break;

		case AST_CONSTINT:
			printf("\t");
			if (r->constInt == -1) printf("iconst_m1");
			else if (r->constInt > -1 && r->constInt <= 5) printf("iconst_%d", r->constInt);
			else if (r->constInt > -128 && r->constInt < 128) printf("bipush %d", r->constInt);
			else printf("ldc %d", r->constInt);
			printf("\n");
			break;

		case AST_CONSTFLOAT:
			printf("\t");
			printf("ldc %f", r->constFloat);
			printf("\n");
			break;

		case AST_VAR:
			printf("\t");
			if (r->tipo == T_INT) printf("iload %d", consultaFrame(r->id));
			else if (r->tipo == T_FLT) printf("fload %d", consultaFrame(r->id));
			else printf("<VAR>");
			printf("\n");
			break;

		case AST_FUNCAO:
			printf("\t");
			printf("unimplemented: funcao", r->id);
			printf("\n");
			break;

		case AST_LISTA:
			if (r->esq != NULL) printAST(r->esq);
			if (r->dir != NULL) printAST(r->dir);
			//printf("\n");
			break;

		case AST_ATRIB:
			printAST(r->dir);
			printf("\t");
			if (r->tipo == T_INT) printf("istore %d", consultaFrame(r->esq->id));
			else if (r->tipo == T_FLT) printf("fstore %d", consultaFrame(r->esq->id));
			else printf("<ATRIB>");
			printf("\n");
			break;

		case AST_NEG:
			printAST(r->esq);
			printf("\t");
			if (r->tipo == T_INT) printf("ineg");
			else if (r->tipo == T_FLT) printf("fneg");
			else printf("<NEG>");
			printf("\n");
			break;

		case AST_I2F:
			printAST(r->esq);
			printf("\t");
			printf("i2f");
			printf("\n");
			break;

		case AST_F2I:
			printAST(r->esq);
			printf("\t");
			printf("f2i");
			printf("\n");
			break;

		case AST_IF:
			labelTrue = labelCounter++;
			if (r->pelse != NULL)
				labelFalse = labelCounter++;
			labelNext = labelCounter++;

			printLogRel(r->cond);
			printf("L%d:", labelTrue);
			printAST(r->pthen);
			if (r->pelse != NULL)
			{
				printf("\tgoto L%d\n", labelNext);
				printf("L%d:", labelFalse);
				printAST(r->pelse);
			}
			printf("L%d:", labelNext);
			break;

		default:
			printf("unimplemented: %d", r->cod);
			printf("\n");
			break;
	}

	//printf("    \t%d\t", r->cod);

	free(r);
	r = NULL;
}

// Impressão pós-ordem
void printLogRel(struct AST * r, int labelTrue, labelFalse)
{
	printf("\t");
	int labelAux;
	switch (r->cod)
	{
		case AST_LOG_AND:
			labelAux = labelCounter++;
			printLogRel(r->esq, labelAux, labelFalse);
			printf("L%d:", labelAux);
			printLogRel(r->dir, labelTrue, labelFalse);
			break;

		case AST_LOG_OR:
			labelAux = labelCounter++;
			printLogRel(r->esq, labelTrue, labelAux);
			printf("L%d:", labelAux);
			printLogRel(r->dir, labelTrue, labelFalse);
			break;

		case AST_LOG_NOT:
			printLogRel(r->esq, labelFalse, labelTrue);
			break;

		case AST_REL:
			printAST(r->esq);
			printAST(r->dir);
			printf("\t");
			if (r->tipo == T_INT) printf("if_icmp");
			else if (r->tipo == T_FLT) printf("if_fcmp");
			switch (r->relop)
			{
				case EQ: printf("eq"); break;
				case NE: printf("ne"); break;
				case LT: printf("lt"); break;
				case LE: printf("le"); break;
				case GT: printf("gt"); break;
				case GE: printf("ge"); break;
				default: printf("ERROR"); break;
			}

			printf(" L%d\n", r->labelTrue
			printf("\tgoto L%d", r->labelFalse);
			printf("\n");
			break;

		default: printf("CAGEI"); break;
	}

	//printf("    \t%d\t", r->cod);

	free(r);
	r = NULL;
}
