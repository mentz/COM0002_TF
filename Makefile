IN = main.c compiler.c
L_IN = compiler.l
S_IN = compiler.y
OUT = a.out

all: LEX SEM OUT

LEX: $(L_IN)
	flex $(L_IN)

IN:
SEM: $(S_IN)
	bison $(S_IN)

OUT: $(IN)
	gcc -o $(OUT) $(IN)

.PHONY: all