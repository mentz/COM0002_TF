#include <stdio.h>
#include "func.h"

extern FILE *yyin;
extern FILE **yyout;

struct CompErrors *err;
struct Simbolo *tabSim = NULL;
int frameNumber = 0;
int labelCounter = 1;

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

	/*
	yyout = fopen(argv[2], "w");
	if (yyout == NULL)
	{
		perror("Erro: Verifique o caminho do arquivo de saída");
		return 1;
	}
	*/

	if (yyparse()) printf("FATAL YYPARSE ABORT\nVeja lista de erros.\n");

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
