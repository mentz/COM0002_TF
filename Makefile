IN = main.c expr.c
OUT = a.out

all: OUT

OUT: $(IN)
	gcc -o $(OUT) $(IN)

.PHONY: all