#define MAX_ID_LEN 11

struct ListaId
{
	struct ListaId *prox;
};

struct Atributo
{
	int tipo;
	struct listaId;
	char id[MAX_ID_LEN];
};

enum {T_INT, T_STR, T_FLT};

struct TabSim
{
	char id[MAX_ID_LEN];
	int tipo;
	struct TabSim *esq, *dir;
};