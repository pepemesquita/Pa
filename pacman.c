#include <stdio.h>
#include <stdlib.h>

char** mapa;
int linhas;
int colunas;

void alocamapa(){
  mapa = malloc(sizeof(char*) * linhas);

  for (int i = 0; i < linhas; i++){
    mapa[i] = malloc(sizeof(char) * (colunas + 1));
  }
}

void lemapa(){
  FILE *f;

  f = fopen("../mapa.txt", "r");

  if (f == NULL) {
    printf("Erro na leitura do mapa");
    exit(1);
  }

  fscanf(f, "%d %d", &linhas, &colunas);
  printf("Linhas = %d Colunas = %d\n", linhas, colunas);

  alocamapa();

  for (int i = 0; i < 5; i++) {
    fscanf(f, "%s", mapa[i]);
  }

  fclose(f);
}

void liberamapa(){
  for (int i = 0; i < linhas; i++){
    free(mapa[i]);
  }

  free(mapa);
}

void imprimemapa(){
  for (int i = 0; i < 5; i++){
    printf("%s\n", mapa[i]);
  }
}

void acabou(){

}


int main() {

  lemapa();

  do{
    imprimemapa();

    
  } while (!acabou());
  
  
  liberamapa();

  
}