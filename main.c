#include <stdio.h>
#include "func.h"

extern FILE *yyin;
FILE *outfile;

struct CompErrors *err;
struct Simbolo *tabSim = NULL;
int frameNumber = 1;
int labelCounter = 1;
char classe[256];

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		printf("Erro: Verifique os argumentos.\n");
		return 1;
	}

	yyin = fopen(argv[1], "r");
	if (yyin == NULL)
	{
		perror("Erro: Verifique o arquivo de entrada");
		return 1;
	}

	outfile = fopen("intermediario.j", "w");
	if (outfile == NULL)
	{
		perror("Erro: Erro ao abrir arquivo intermediario.j");
		return 1;
	}

	printf("classe = %s\n", argv[1]); fflush(stdout);
	strncpy(classe, argv[1], (int) strlen(argv[1]) - 4);

	fprintf(outfile, ".class public %s\n"
					 ".super java/lang/Object\n\n", classe);

	if (yyparse())
	{
		printf("FATAL YYPARSE ABORT\nVeja lista de erros.\n");
		remove("intermediario.j");
	}
	else
	{
		char saida[256] = "";
		strcat(saida, classe); strcat(saida, ".j\0");
		printf("saida = %s\n", saida); fflush(stdout);
		rename("intermediario.j", saida);
	}

	fclose(yyin);

	// IMPRIMIR TABELA DE SÍMBOLOS AQUI.
	printf("\n");
	printf("Símbolo    | Frame | Tipo\n");
	printf("-----------+-------+-------\n");
	printTabSim(tabSim);
	printf("-----------+-------+-------\n\n");
	printErrors();

	return 0;
}
