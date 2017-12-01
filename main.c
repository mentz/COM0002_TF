#include <stdio.h>
#include "func.h"

extern FILE *yyin;
FILE *outfile;

struct CompErrors *err;
struct Simbolo *tabSim = NULL;
int frameNumber = 1;
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

	outfile = fopen("intermediario.j", "w");
	if (outfile == NULL)
	{
		perror("Erro: Erro ao abrir arquivo intermediario.j");
		return 1;
	}

	fprintf(outfile, ".class public FelizNatalCristiano\n"
					 ".super java/lang/Object\n"

					 "\n.method public <init>()V\n" 
					 	"\taload_0\n" 
					 	"\tinvokenonvirtual java/lang/Object/<init>()V\n" 
					 	"\treturn\n"
					 ".end method\n"

					 "\n.method public static main([Ljava/lang/String;)V\n"
					 	"\t.limit stack 10\n"
						"\t.limit locals ");
	
	if (yyparse())
	{
		printf("FATAL YYPARSE ABORT\nVeja lista de erros.\n");
		remove("intermediario.j");
	}
	else
	{
		rename("intermediario.j", "saida.j");
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
