#include <stdio.h>
#include <stdlib.h>

void move(char move);
int acabou();

typedef struct mapa MAPA;
typedef struct posicao POSICAO;
struct mapa {
    char** matriz;
    int linhas;
    int colunas; 
};

struct posicao{
    int x,y;
};

void alocamapa(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas);

    for (int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void lemapa(MAPA* m){
    FILE *f;

    f = fopen("../mapa.txt", "r");

    if (f == NULL) {
        printf("Erro na leitura do mapa");
        exit(1);
    }

    fscanf(f, "%d %d", &m->linhas, &m->colunas);
    printf("Linhas = %d Colunas = %d\n", m->linhas, m->colunas);

    alocamapa(m);

    for (int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

void liberamapa(MAPA* m){
    for(int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }

    free(m->matriz);
}

void imprimemapa(MAPA* m){
    for (int i = 0; i < m->linhas; i++){
        printf("%s\n", m->matriz[i]);
    }
}

void encontramapa(MAPA* m, POSICAO* p, char c){
    for (int i = 0; i < m->linhas; i++){
        for (int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == '@'){  
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

// Declare the functions here in the header file, no need to redeclare in the implementation
void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void liberamapa(MAPA* m);
void imprimemapa(MAPA* m);
