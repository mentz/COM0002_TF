#define MAX_ID_LEN 11

struct ListaId
{
	char id[MAX_ID_LEN];
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

struct ListaId criarLista(char id[MAX_ID_LEN]);

void insLista(struct ListaId lista, char id[MAX_ID_LEN]);

void insTabSim(int tipo, struct ListaId lista);
