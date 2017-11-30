#include "func.h"

extern CompErrors *err;
extern Simbolo *tabSim;
extern int frameNumber;
extern int labelCounter;

void addError(int error, int line)
{
	CompErrors *aux = err, *aux2;

	while (aux != NULL)
	{
		aux2 = aux;
		aux  = aux->next;
	}

	aux = malloc(sizeof(CompErrors));
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
	CompErrors *aux = err;
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
ListaId* criarLista(char *id)
{
	ListaId *ret;
	ret = malloc(sizeof(ListaId));
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
ListaId* insLista(Atributo *atr, char *id)
{
	ListaId *aux = atr->listaId, *novo = NULL;

	novo = malloc(sizeof(ListaId));
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
void insTabSim(int tipo, ListaId *lista)
{
	Simbolo *noTabSim = tabSim, *novoSimbolo = NULL;

	int direcao = -1;
	ListaId *lista_aux = lista, *lista_aux2 = NULL;
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
			}
			else
			{
				if (noTabSim->dir != NULL)
					noTabSim = noTabSim->dir;
				else
				{
					direcao = 1; // DIREITA
					break;
				}
			}
		}

		novoSimbolo = malloc(sizeof(Simbolo));
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
	Simbolo * aux = tabSim, *aux2;
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
	Simbolo * aux = tabSim;
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

void freeLista(ListaId *lista)
{
	ListaId *aux = lista, *aux2 = NULL;
	while (aux != NULL)
	{
		aux2 = aux;
		aux = aux->prox;
		free(aux2);
		aux2 = NULL;
	}
	aux = NULL;
}

void printTabSim(Simbolo *tabSim)
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
AST * criarFolhaID(int cod, char *nome)
{
	AST * folha = malloc(sizeof(AST));
	if (folha == NULL)
	{
		perror("Erro: [criarFolhaID] - malloc(AST): ");
		exit(EXIT_FAILURE);
	}

	folha->cod		= cod;
	folha->tipo		= consultaTipo(nome);
	strncpy(folha->id, nome, MAX_ID_LEN);

	return folha;
}

// AST
AST * criarFolhaInt(int value)
{
	AST * folha = malloc(sizeof(AST));
	if (folha == NULL)
	{
		perror("Erro: [criarFolhaInt] - malloc(AST): ");
		exit(EXIT_FAILURE);
	}

	folha->cod 		= AST_CONSTINT;
	folha->tipo		= T_INT;
	folha->constInt = value;

	return folha;
}

// AST
AST * criarFolhaFloat(float value)
{
	AST * folha = malloc(sizeof(AST));
	if (folha == NULL)
	{
		perror("Erro: [criarFolhaFloat] - malloc(AST): ");
		exit(EXIT_FAILURE);
	}

	folha->cod 		  = AST_CONSTFLOAT;
	folha->tipo		  = T_FLT;
	folha->constFloat = value;

	return folha;
}

// AST
AST * criarNoAST(int cod, AST * esq, AST * dir)
{
	AST * no = malloc(sizeof(AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoAST] - malloc(AST)");
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
AST * i2fAST(AST * iptr) {
	AST * no = malloc(sizeof(AST));
	if (no == NULL)
	{
		perror("Erro: [i2fAST] - malloc(AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = AST_I2F;
	no->tipo = T_FLT;
	no->esq  = iptr;

	return no;
}

// Cria um nó Float2Int, retorna seu endereço e aponta para iptr;
AST * f2iAST(AST * iptr) {
	AST * no = malloc(sizeof(AST));
	if (no == NULL)
	{
		perror("Erro: [f2iAST] - malloc(AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = AST_F2I;
	no->tipo = T_FLT;
	no->esq  = iptr;

	return no;
}

// No Aritmético
AST * criarNoArit(int op, AST *esq, AST *dir)
{
	AST *no = malloc(sizeof(AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoArit] - malloc(AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = op;
	no->esq  = esq;
	no->dir  = dir;
	no->tipo = esq->tipo;

	return no;
}

// No Lógico-Relacional
AST * criarNoRel(int op, AST * esq, AST * dir)
{
	AST * no = malloc(sizeof(AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoRel] - malloc(AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = op;
	no->esq  = esq;
	no->dir  = dir;
	no->tipo = esq->tipo;

	return no;
}

// Cria um nó IF, retorna seu endereço;
AST * criarNoIF(AST * cond, AST * b1, AST * b2)
{
	AST * no = malloc(sizeof(AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoIF] - malloc(AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = AST_IF;
	no->cond = cond;
	no->pthen  = b1;
	no->pelse  = b2;

	return no;
}

// Cria um nó WHILE, retorna seu endereço;
AST * criarNoWhile(AST * cond, AST * b1)
{
	AST * no = malloc(sizeof(AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoWhile] - malloc(AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = AST_WHILE;
	no->cond = cond;
	no->pthen  = b1;

	return no;
}

// Impressão pós-ordem
void printAST(AST * r)
{
	int labelTrue, labelFalse, labelNext, labelAux;
	switch (r->cod)
	{
		case AST_ARIT_ADD:
			printAST(r->esq);
			printAST(r->dir);
			printf("\t");
			switch (r->tipo)
			{
				case T_INT: printf("i"); break;
				case T_FLT: printf("f"); break;
			}
			printf("add");
			printf("\n");
			break;

		case AST_ARIT_SUB:
			printAST(r->esq);
			printAST(r->dir);
			printf("\t");
			switch (r->tipo)
			{
				case T_INT: printf("i"); break;
				case T_FLT: printf("f"); break;
			}
			printf("sub");
			printf("\n");
			break;
			
		case AST_ARIT_MUL:
			printAST(r->esq);
			printAST(r->dir);
			printf("\t");
			switch (r->tipo)
			{
				case T_INT: printf("i"); break;
				case T_FLT: printf("f"); break;
			}
			printf("mul");
			printf("\n");
			break;
			
		case AST_ARIT_DIV:
			printAST(r->esq);
			printAST(r->dir);
			printf("\t");
			switch (r->tipo)
			{
				case T_INT: printf("i"); break;
				case T_FLT: printf("f"); break;
			}
			printf("div");
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

			printLogRel(r->cond, labelTrue, labelNext);
			printf("L%d:\n", labelTrue);
			printAST(r->pthen);
			if (r->pelse != NULL)
			{
				printf("\tgoto L%d\n", labelNext);
				printf("L%d:\n", labelFalse);
				printAST(r->pelse);
			}
			printf("L%d:\n", labelNext);
			break;

		case AST_WHILE:
			labelAux  = labelCounter++;
			labelTrue = labelCounter++;
			labelNext = labelCounter++;

			printf("L%d:\n", labelAux);
			printLogRel(r->cond, labelTrue, labelNext);
			printf("L%d:\n", labelTrue);
			printAST(r->pthen);
			printf("\tgoto %d\n", labelAux);
			printf("L%d:\n", labelNext);
			break;

		case AST_PRINT:
			printf("\tinvokevirtual java/lang/System/out Ljava/io/PrintStream;\n");
			printAST(r->esq);
			printf("invokevirtual java/io/PrintStream/print(");
			switch (r->tipo)
			{
				case T_INT: printf("i"); break;
				case T_FLT: printf("f"); break;
				case T_STR: printf("Ljava/lang/String"); break;
				default: printf("ERRO <AST_PRINT>");
			}
			printf(";)V\n");
			break;

		case AST_PRINTLN:
			printf("\tinvokevirtual java/lang/System/out Ljava/io/PrintStream;\n");
			printAST(r->esq);
			printf("invokevirtual java/io/PrintStream/println(");
			switch (r->tipo)
			{
				case T_INT: printf("i"); break;
				case T_FLT: printf("f"); break;
				case T_STR: printf("Ljava/lang/String"); break;
				default: printf("ERRO <AST_PRINT>");
			}
			printf(";)V\n");
			break;

		default:
			printf("unimplemented: %d", r->cod);
			printf("\n");
			break;
	}

	free(r);
	r = NULL;
}

// Impressão pós-ordem
void printLogRel(AST * r, int labelTrue, int labelFalse)
{
	int labelAux;
	switch (r->cod)
	{
		case AST_LOG_AND:
			labelAux = labelCounter++;
			printLogRel(r->esq, labelAux, labelFalse);
			printf("L%d:\n", labelAux);
			printLogRel(r->dir, labelTrue, labelFalse);
			break;

		case AST_LOG_OR:
			labelAux = labelCounter++;
			printLogRel(r->esq, labelTrue, labelAux);
			printf("L%d:\n", labelAux);
			printLogRel(r->dir, labelTrue, labelFalse);
			break;

		case AST_LOG_NOT:
			printLogRel(r->esq, labelFalse, labelTrue);
			break;

		case AST_REL_EQ:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: printf("\tif_icmp"); break;
				case T_FLT: printf("\tif_fcmp"); break;
			}
			printf("eq");

			printf(" L%d\n", labelTrue);
			printf("\tgoto L%d", labelFalse);
			printf("\n");
			break;

		case AST_REL_NE:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: printf("\tif_icmp"); break;
				case T_FLT: printf("\tif_fcmp"); break;
			}
			printf("ne");

			printf(" L%d\n", labelTrue);
			printf("\tgoto L%d", labelFalse);
			printf("\n");
			break;

		case AST_REL_LT:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: printf("\tif_icmp"); break;
				case T_FLT: printf("\tif_fcmp"); break;
			}
			printf("lt");

			printf(" L%d\n", labelTrue);
			printf("\tgoto L%d", labelFalse);
			printf("\n");
			break;

		case AST_REL_LE:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: printf("\tif_icmp"); break;
				case T_FLT: printf("\tif_fcmp"); break;
			}
			printf("le");

			printf(" L%d\n", labelTrue);
			printf("\tgoto L%d", labelFalse);
			printf("\n");
			break;

		case AST_REL_GT:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: printf("\tif_icmp"); break;
				case T_FLT: printf("\tif_fcmp"); break;
			}
			printf("gt");

			printf(" L%d\n", labelTrue);
			printf("\tgoto L%d", labelFalse);
			printf("\n");
			break;

		case AST_REL_GE:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: printf("\tif_icmp"); break;
				case T_FLT: printf("\tif_fcmp"); break;
			}
			printf("ge");

			printf(" L%d\n", labelTrue);
			printf("\tgoto L%d", labelFalse);
			printf("\n");
			break;

			

		default: printf("CAGEI\n"); break;
	}

	//printf("    \t%d\t", r->cod);

	free(r);
	r = NULL;
}
