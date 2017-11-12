IN = main.c func.c compiler.c
L_IN = compiler.l
S_IN = compiler.y
OUT = compiler

all: LEX SEM OUT

LEX: $(L_IN)
	flex $(L_IN)

IN:
SEM: $(S_IN)
	bison --verbose $(S_IN)

OUT: $(IN)
	gcc -o $(OUT) $(IN) -fmax-errors=3 -lm

.PHONY: all
