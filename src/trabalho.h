
// Controle de Trens e Vagões

typedef struct node{

    int maxQtd;
    char tipoCarga[100];
    struct node *prox;
    struct node *ant;



} NoVagoes;

typedef struct nose {
    char train[100];
    NoVagoes *vagoes;
    struct nose *prox;
} NoTrens;


void crialistaTrem(NoTrens **listaTrens);
void adicionaTrem(NoTrens **listaTrens, char *nome);
int adicionaVagao(NoTrens **listaTrens, char *nome, char *tipoCarga, int qtd);
void printaLista(NoTrens **listaTrens);
void removerTrem(NoTrens **listaTrens, char *nome);
void removerVagao(NoTrens **listaTrens, char* nomeTrem, char *nomeVagao);
