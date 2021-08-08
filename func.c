#include "func.h"

extern CompErrors *err;
extern Simbolo *tabSim;
extern int frameNumber;
extern int labelCounter;
extern FILE *outfile;
extern char classe[256];

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

			case ERR_4:
				printf("- Linha %d - Erro: Atribuindo valor inválido a tipo string.", aux->line);
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
	ListaId *lista_aux = lista;
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
AST * criarFolhaLiteral(char *text)
{
	AST * folha = malloc(sizeof(AST));
	if (folha == NULL)
	{
		perror("Erro: [criarFolhaFloat] - malloc(AST): ");
		exit(EXIT_FAILURE);
	}

	folha->cod 	 = AST_LITERAL;
	folha->tipo	 = T_STR;
	strncpy(folha->text, text, MAX_TEXT_LEN);

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

// Cria um nó DO-WHILE, retorna seu endereço;
AST * criarNoDoWhile(AST * cond, AST * b1)
{
	AST * no = malloc(sizeof(AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoDoWhile] - malloc(AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = AST_DOWHILE;
	no->cond = cond;
	no->pthen  = b1;

	return no;
}

AST * criarNoAuto(int tipo, AST * var, AST * incr)
{
	AST * no = malloc(sizeof(AST));
	if (no == NULL)
	{
		perror("Erro: [criarNoWhile] - malloc(AST)");
		exit(EXIT_FAILURE);
	}

	no->cod  = tipo;
	no->esq  = var;
	no->dir  = incr;
	no->tipo = no->esq->tipo;

	return no;
}

// Imprime quantidade de variáveis
void printInicioArquivo()
{
	printStrings(tabSim);
	fprintf(outfile, "\n.method public <init>()V\n" 
					 	"\taload_0\n" 
					 	"\tinvokenonvirtual java/lang/Object/<init>()V\n" 
					 	"\treturn\n"
					 ".end method\n"

					 "\n.method public static main([Ljava/lang/String;)V\n"
					 	"\t.limit stack 10\n"
						"\t.limit locals %d\n", frameNumber);
}

// Imprime variáveis para guardar strings
void printStrings(Simbolo *tabSim)
{
	if (tabSim != NULL)
	{
		printStrings(tabSim->dir);
		printStrings(tabSim->esq);

		switch(tabSim->tipo)
		{
			case T_STR: fprintf(outfile, ".field static private %s Ljava/lang/String;\n", tabSim->id); break;
			default: break;
		}
	}
}

// Imprime final da função principal
void printFinalMain()
{
	fprintf(outfile, "\treturn\n"
					 ".end method\n");
}

// Impressão pós-ordem
void printAST(AST * r)
{
	int labelTrue, labelFalse, labelNext, labelAux, aux;
	switch (r->cod)
	{
		case AST_ARIT_ADD:
			printAST(r->esq);
			printAST(r->dir);
			fprintf(outfile, "\t");
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "i"); break;
				case T_FLT: fprintf(outfile, "f"); break;
			}
			fprintf(outfile, "add");
			fprintf(outfile, "\n");
			break;

		case AST_ARIT_SUB:
			printAST(r->esq);
			printAST(r->dir);
			fprintf(outfile, "\t");
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "i"); break;
				case T_FLT: fprintf(outfile, "f"); break;
			}
			fprintf(outfile, "sub");
			fprintf(outfile, "\n");
			break;
			
		case AST_ARIT_MUL:
			printAST(r->esq);
			printAST(r->dir);
			fprintf(outfile, "\t");
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "i"); break;
				case T_FLT: fprintf(outfile, "f"); break;
			}
			fprintf(outfile, "mul");
			fprintf(outfile, "\n");
			break;
			
		case AST_ARIT_DIV:
			printAST(r->esq);
			printAST(r->dir);
			fprintf(outfile, "\t");
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "i"); break;
				case T_FLT: fprintf(outfile, "f"); break;
			}
			fprintf(outfile, "div");
			fprintf(outfile, "\n");
			break;

		case AST_CONSTINT:
			fprintf(outfile, "\t");
			if (r->constInt == -1) fprintf(outfile, "iconst_m1");
			else if (r->constInt > -1 && r->constInt <= 5) fprintf(outfile, "iconst_%d", r->constInt);
			else if (r->constInt > -128 && r->constInt < 128) fprintf(outfile, "bipush %d", r->constInt);
			else fprintf(outfile, "ldc %d", r->constInt);
			fprintf(outfile, "\n");
			break;

		case AST_CONSTFLOAT:
			fprintf(outfile, "\t");
			fprintf(outfile, "ldc %f", r->constFloat);
			fprintf(outfile, "\n");
			break;

		case AST_LITERAL:
			fprintf(outfile, "\t");
			fprintf(outfile, "ldc %s", r->text);
			fprintf(outfile, "\n");
			break;

		case AST_VAR:
			fprintf(outfile, "\t");
			if (r->tipo == T_INT) fprintf(outfile, "iload %d", consultaFrame(r->id));
			else if (r->tipo == T_FLT) fprintf(outfile, "fload %d", consultaFrame(r->id));
			else if (r->tipo == T_STR) fprintf(outfile, "getstatic %s/%s Ljava/lang/String;", classe, r->id);
			else fprintf(outfile, "<VAR>");
			fprintf(outfile, "\n");
			break;

		case AST_FUNCAO:
			fprintf(outfile, "\t");
			fprintf(outfile, "unimplemented: funcao %s", r->id);
			fprintf(outfile, "\n");
			break;

		case AST_LISTA:
			if (r->esq != NULL) printAST(r->esq);
			if (r->dir != NULL) printAST(r->dir);
			break;

		case AST_ATRIB:
			printAST(r->dir);
			fprintf(outfile, "\t");
			if (r->tipo == T_INT) fprintf(outfile, "istore %d", consultaFrame(r->esq->id));
			else if (r->tipo == T_FLT) fprintf(outfile, "fstore %d", consultaFrame(r->esq->id));
			else if (r->tipo == T_STR) fprintf(outfile, "putstatic %s/%s Ljava/lang/String;", classe, r->esq->id);
			else fprintf(outfile, "<ATRIB>");
			fprintf(outfile, "\n");
			break;

		case AST_NEG:
			printAST(r->esq);
			fprintf(outfile, "\t");
			if (r->tipo == T_INT) fprintf(outfile, "ineg");
			else if (r->tipo == T_FLT) fprintf(outfile, "fneg");
			else fprintf(outfile, "<NEG>");
			fprintf(outfile, "\n");
			break;

		case AST_I2F:
			printAST(r->esq);
			fprintf(outfile, "\t");
			fprintf(outfile, "i2f");
			fprintf(outfile, "\n");
			break;

		case AST_F2I:
			printAST(r->esq);
			fprintf(outfile, "\t");
			fprintf(outfile, "f2i");
			fprintf(outfile, "\n");
			break;

		case AST_IF:
			labelTrue = labelCounter++;
			if (r->pelse != NULL)
				labelFalse = labelCounter++;
			labelNext = labelCounter++;

			printLogRel(r->cond, labelTrue, labelNext);
			fprintf(outfile, "  l%d:\n", labelTrue);
			printAST(r->pthen);
			if (r->pelse != NULL)
			{
				fprintf(outfile, "\tgoto l%d\n", labelNext);
				fprintf(outfile, "  l%d:\n", labelFalse);
				printAST(r->pelse);
			}
			fprintf(outfile, "  l%d:\n", labelNext);
			break;

		case AST_WHILE:
			labelAux  = labelCounter++;
			labelTrue = labelCounter++;
			labelNext = labelCounter++;

			fprintf(outfile, "  l%d:\n", labelAux);
			printLogRel(r->cond, labelTrue, labelNext);
			fprintf(outfile, "  l%d:\n", labelTrue);
			printAST(r->pthen);
			fprintf(outfile, "\tgoto l%d\n", labelAux);
			fprintf(outfile, "  l%d:\n", labelNext);
			break;

		case AST_DOWHILE:
			labelAux  = labelCounter++;
			labelTrue = labelCounter++;
			labelNext = labelCounter++;

			fprintf(outfile, "\tgoto l%d\n", labelTrue);
			fprintf(outfile, "  l%d:\n", labelAux);
			printLogRel(r->cond, labelTrue, labelNext);
			fprintf(outfile, "  l%d:\n", labelTrue);
			printAST(r->pthen);
			fprintf(outfile, "\tgoto l%d\n", labelAux);
			fprintf(outfile, "  l%d:\n", labelNext);
			break;

		case AST_PRINT:
			fprintf(outfile, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
			printAST(r->esq);
			fprintf(outfile, "\tinvokevirtual java/io/PrintStream/print(");
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "I"); break;
				case T_FLT: fprintf(outfile, "F"); break;
				case T_STR: fprintf(outfile, "Ljava/lang/String;"); break;
				default: fprintf(outfile, "ERRO <AST_PRINT>");
			}
			fprintf(outfile, ")V\n");
			break;

		case AST_AUTO_ADD:
			aux = consultaFrame(r->esq->id);
			printAST(r->esq);
			printAST(r->dir);
			fprintf(outfile, "\t");
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "iadd\n\tistore %d", aux); break;
				case T_FLT: fprintf(outfile, "fadd\n\tfstore %d", aux); break;
				default: fprintf(outfile, "ERRO <AST_AUTO_ADD>");
			}
			fprintf(outfile, "\n");
			break;

		case AST_AUTO_SUB:
			aux = consultaFrame(r->esq->id);
			printAST(r->esq);
			printAST(r->dir);
			fprintf(outfile, "\t");
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "isub\n\tistore %d", aux); break;
				case T_FLT: fprintf(outfile, "fsub\n\tfstore %d", aux); break;
				default: fprintf(outfile, "ERRO <AST_AUTO_SUB>");
			}
			fprintf(outfile, "\n");
			break;

		case AST_AUTO_MUL:
			aux = consultaFrame(r->esq->id);
			printAST(r->esq);
			printAST(r->dir);
			fprintf(outfile, "\t");
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "imul\n\tistore %d", aux); break;
				case T_FLT: fprintf(outfile, "fmul\n\tfstore %d", aux); break;
				default: fprintf(outfile, "ERRO <AST_AUTO_MUL>");
			}
			fprintf(outfile, "\n");
			break;

		case AST_AUTO_DIV:
			aux = consultaFrame(r->esq->id);
			printAST(r->esq);
			printAST(r->dir);
			fprintf(outfile, "\t");
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "idiv\n\tistore %d", aux); break;
				case T_FLT: fprintf(outfile, "fdiv\n\tfstore %d", aux); break;
				default: fprintf(outfile, "ERRO <AST_AUTO_DIV>");
			}
			fprintf(outfile, "\n");
			break;

		default:
			fprintf(outfile, "unimplemented: %d", r->cod);
			fprintf(outfile, "\n");
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
			fprintf(outfile, "  l%d:\n", labelAux);
			printLogRel(r->dir, labelTrue, labelFalse);
			break;

		case AST_LOG_OR:
			labelAux = labelCounter++;
			printLogRel(r->esq, labelTrue, labelAux);
			fprintf(outfile, "  l%d:\n", labelAux);
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
				case T_INT: fprintf(outfile, "\tif_icmp"); break;
				case T_FLT: fprintf(outfile, "\tif_fcmp"); break;
			}
			fprintf(outfile, "eq");

			fprintf(outfile, " l%d\n", labelTrue);
			fprintf(outfile, "\tgoto l%d", labelFalse);
			fprintf(outfile, "\n");
			break;

		case AST_REL_NE:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "\tif_icmp"); break;
				case T_FLT: fprintf(outfile, "\tif_fcmp"); break;
			}
			fprintf(outfile, "ne");

			fprintf(outfile, " l%d\n", labelTrue);
			fprintf(outfile, "\tgoto l%d", labelFalse);
			fprintf(outfile, "\n");
			break;

		case AST_REL_LT:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "\tif_icmp"); break;
				case T_FLT: fprintf(outfile, "\tif_fcmp"); break;
			}
			fprintf(outfile, "lt");

			fprintf(outfile, " l%d\n", labelTrue);
			fprintf(outfile, "\tgoto l%d", labelFalse);
			fprintf(outfile, "\n");
			break;

		case AST_REL_LE:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "\tif_icmp"); break;
				case T_FLT: fprintf(outfile, "\tif_fcmp"); break;
			}
			fprintf(outfile, "le");

			fprintf(outfile, " l%d\n", labelTrue);
			fprintf(outfile, "\tgoto l%d", labelFalse);
			fprintf(outfile, "\n");
			break;

		case AST_REL_GT:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "\tif_icmp"); break;
				case T_FLT: fprintf(outfile, "\tif_fcmp"); break;
			}
			fprintf(outfile, "gt");

			fprintf(outfile, " l%d\n", labelTrue);
			fprintf(outfile, "\tgoto l%d", labelFalse);
			fprintf(outfile, "\n");
			break;

		case AST_REL_GE:
			printAST(r->esq);
			printAST(r->dir);
			switch (r->tipo)
			{
				case T_INT: fprintf(outfile, "\tif_icmp"); break;
				case T_FLT: fprintf(outfile, "\tif_fcmp"); break;
			}
			fprintf(outfile, "ge");

			fprintf(outfile, " l%d\n", labelTrue);
			fprintf(outfile, "\tgoto l%d", labelFalse);
			fprintf(outfile, "\n");
			break;

			

		default: fprintf(outfile, "CAGEI\n"); break;
	}

	//printf("    \t%d\t", r->cod);

	free(r);
	r = NULL;
}
