#include <stdio.h>
#include "func.h"

extern FILE *yyin;

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

	fclose(yyin);

	// IMPRIMIR TABELA DE SÍMBOLOS AQUI.
	printf("\n");
	printf("Símbolo    | Tipo\n");
	printf("-----------------\n");
	printTabSim(tabSim);

	return 0;
}
