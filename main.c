#include <stdio.h>
#include "func.h"

extern FILE *yyin;

struct CompErrors *err;
struct Simbolo *tabSim = NULL;
int frameNumber = 0;

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
		perror("Erro: Verifique o arquivo");
		return 1;
	}

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
