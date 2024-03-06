#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para substituir uma string por outra string
char *substituirPalavra(const char *s, const char *velho, const char *novo) {
  char *result;
  int i, cnt = 0;
  int novolen = strlen(novo);
  int velholen = strlen(velho);

  for (i = 0; s[i] != '\0'; i++) {
    if (strstr(&s[i], velho) == &s[i]) {
      cnt++;

      i += velholen - 1;
    }
  }

  result = (char *)malloc(i + cnt * (novolen - velholen) + 1);

  i = 0;
  while (*s) {
    if (strstr(s, velho) == s) {
      strcpy(&result[i], novo);
      i += novolen;
      s += velholen;
    } else
      result[i++] = *s++;
  }

  result[i] = '\0';
  return result;
}

void string(char *nome_arquivo_entrada, char *string_procurada,
            char *string_substituta, char *nome_arquivo_saida) {

  char *result = NULL;

  FILE *arquivo_entrada;
  char str[50];
  int i;
  int tamanho;

  arquivo_entrada = fopen(nome_arquivo_entrada, "w");
  if (arquivo_entrada == NULL) {
    printf("Erro ao tentar abrir o arquivo!");
    exit(1);
  }

  printf("Digite a frase a ser gravada no arquivo: ");
  scanf(" %[^\n]", str);

  // fputs(str, arquivo_entrada);

  tamanho = strlen(str);

  // gravando caracter por caracter
  for (i = 0; i < tamanho; i++) {
    fputc(str[i], arquivo_entrada);
  }

  fclose(arquivo_entrada);

  FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");

  if (arquivo_saida == NULL) {
    printf("Erro ao abrir o arquivo de saída.\n");
    return;
  }

  printf("Digite uma palavra a ser procurada na frase: ");
  scanf(" %s", string_procurada);

  printf("Digite a palavra para substituir a palavra a ser procurada: ");
  scanf("%s  ", string_substituta);

  result = substituirPalavra(str, string_procurada, string_substituta);

  fprintf(arquivo_saida, "%s", result);
  fclose(arquivo_saida);

  printf("Substituição concluída com sucesso.\n");
}

int main() {
  char nome_arquivo_entrada[100];
  char string_procurada[100];
  char string_substituta[100];
  char nome_arquivo_saida[100];

  printf("Digite o nome do arquivo de entrada: ");
  scanf("%s", nome_arquivo_entrada);

  printf("Digite o nome do arquivo de saída: ");
  scanf("%s", nome_arquivo_saida);

  /*printf("Digite uma palavra a ser procurada na frase: ");
  scanf("%s ", string_procurada);

  printf("Digite a palavra para substituir a palavra a ser procurada: ");
  scanf("%s ", string_substituta);*/

  string(nome_arquivo_entrada, string_procurada, string_substituta,

         nome_arquivo_saida);

  return 0;
}
