#include <stdio.h>
#include <stdlib.h>

void ordena_num(int vetor[], int tam) {
  for (int i = 0; i < tam; i++) {
    for (int j = i; j < tam; j++) {
      if (vetor[i] > vetor[j]) {
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
      }
    }
  }
}

void ordena_arquivo(char *nome_arquivo_entrada, char *nome_arquivo_saida) {
  int vetor[100] = {};
  int tam = 5;
  FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "w");
  // int vetA[tam], vetB[tam];
  if (arquivo_entrada == NULL) {
    printf("Erro ao abrir o arquivo de entrada.\n");
    return;
  }
  printf("Escreva os números: \n");
  for (int i = 0; i < tam; i++) {
    scanf("%d", &vetor[i]);
    fprintf(arquivo_entrada, "%d\n", vetor[i]);
  }
  fclose(arquivo_entrada);

  FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");
  printf("\nLendo os numeros ordenados: \n");
  ordena_num(vetor, tam);
  for (int i = 0; i < tam; i++) {
    fprintf(arquivo_saida, "%d ", vetor[i]);
    printf("%d ", vetor[i]);
    fscanf(arquivo_saida, "%d \n", &tam);
  }

  fclose(arquivo_saida);
  printf("\nOrdenação concluída com sucesso.\n");

  return;
}

int main() {
  char nome_arquivo_entrada[100];
  char nome_arquivo_saida[100];

  printf("Digite o nome do arquivo de entrada: ");
  scanf("%s", nome_arquivo_entrada);

  printf("Digite o nome do arquivo de saída: ");
  scanf("%s", nome_arquivo_saida);

  ordena_arquivo(nome_arquivo_entrada, nome_arquivo_saida);

  return 0;
}
