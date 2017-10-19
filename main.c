#include <stdio.h>
#include "func.h"

extern FILE *yyin;
extern int linha = 1;

struct Simbolo *tabSim = NULL;

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		printf("Erro. Verifique os argumentos.\n");
		return 1;
	}

	yyin = fopen(argv[1], "r");
	if (yyin == NULL)
	{
		perror("Erro de execução: Verifique o arquivo.\nErro: ");
		return 1;
	}

	yyparse();

	// IMPRIMIR TABELA DE SÍMBOLOS AQUI.
	printTabSim();

	return 0;
}
