#include <stdio.h>
#include <stdlib.h>

void gerarNumerosAleatorios(int quantidade, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  for (int i = 0; i < quantidade; i++) {
    int numero = rand() % 20 + 1;
    fwrite(&numero, sizeof(int), 1, arquivo);
    printf("%d ", rand() % 20);
    printf("\n");
  }

  fclose(arquivo);
}

void calcularEstatisticas(const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  int numero;
  int soma = 0;
  int quantidade = 0;

  while (fread(&numero, sizeof(int), 1, arquivo) == 1) {
    soma += numero;
    quantidade++;
  }

  float media = (float)soma / quantidade;

  fclose(arquivo);
  printf("Soma: %d\n", soma);
  printf("Média: %.2f\n", media);
  printf("Quantidade: %d\n", quantidade);

  FILE *arquivoResultadoTotal = fopen("resultadoTotal.bin", "ab");

  if (arquivoResultadoTotal == NULL) {
    printf("Erro ao abrir o arquivo de resultado total.\n");
    return;
  }

  fwrite(&soma, sizeof(int), 1, arquivoResultadoTotal);
  fwrite(&media, sizeof(float), 1, arquivoResultadoTotal);
  fwrite(&quantidade, sizeof(int), 1, arquivoResultadoTotal);

  fclose(arquivoResultadoTotal);
}

int main() {

  srand(time(NULL));

  int quantidade;
  char nomeArquivo[100];

  printf("Digite a quantidade de números a serem gerados: ");
  scanf("%d", &quantidade);

  printf("Digite o nome do arquivo para salvar os números: ");
  scanf("%s", nomeArquivo);

  gerarNumerosAleatorios(quantidade, nomeArquivo);
  calcularEstatisticas(nomeArquivo);

  return 0;
}
