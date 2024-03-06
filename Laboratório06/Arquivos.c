#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 30

void filtra_nomes(char *nome_arquivo_entrada, char letra_inicial,
                  char *nome_arquivo_saida) {
  FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "w");

  char nome[20], sobrenome[20], i;
  int idade;
  if (arquivo_entrada == NULL) {
    printf("Erro ao abrir o arquivo de entrada.\n");
    return;
  }
  printf("Entre com o nome, sobrenome e idade de %d pessoas\n", TAM);
  for (i = 0; i < TAM; i++) {
    printf("Pessoa %d. Entre nome: ", i + 1);
    scanf("%s", nome);

    printf("Pessoa %d. Entre sobrenome: ", i + 1);
    scanf("%s", sobrenome);

    printf("Pessoa %d. Entre idade: ", i + 1);
    scanf("%d", &idade);

    fputs(nome, arquivo_entrada);
    fputs(" ", arquivo_entrada);
    fputs(sobrenome, arquivo_entrada);
    fputs(" ", arquivo_entrada);
    fprintf(arquivo_entrada, "%d\n", idade);
  }
  fclose(arquivo_entrada);

  FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");
  char linha[100];
  if (arquivo_saida == NULL) {
    printf("Erro ao abrir o arquivo de saída.\n");
  }

  printf("Digite a letra inicial para filtrar os nomes: ");
  scanf(" %c", &letra_inicial);

  if (nome[0] == letra_inicial) {
    fprintf(arquivo_saida, "%s %s %d\n", nome, sobrenome, idade);
  }

  fclose(arquivo_saida);

  printf("Filtro concluído com sucesso.\n");
}

int main() {
  char nome_arquivo_entrada[100];
  char letra_inicial;
  char nome_arquivo_saida[100];

  printf("Digite o nome do arquivo de entrada: ");
  scanf("%s", nome_arquivo_entrada);

  printf("Digite o nome do arquivo de saída: ");
  scanf("%s", nome_arquivo_saida);

  filtra_nomes(nome_arquivo_entrada, letra_inicial, nome_arquivo_saida);

  return 0;
}
