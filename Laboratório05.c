#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define alfabeto 26
#define tam2 100
#define tam3 80

void frequencia(char *str, int tam) {
  int aux[alfabeto] = {0};
  for (int i = 0; i < tam; i++) {
    aux[str[i] - 97]++;
  }
  for (int i = 0; i < alfabeto; i++) {
    if (aux[i] != 0) {
      printf("\n%c = %d\n", i + 97, aux[i]);
    }
  }
}

void exercicio1() {
  int tam;
  char *str;

  printf("Digite o tamanho da sua palavra\n");
  scanf("%d", &tam);

  // tam[strlen(tam)-1]='\0';
  printf("Digite sua palavra\n");
  str = (char *)malloc(sizeof(char) * tam);
  // fgets (str,tam,stdin);
  scanf("%s", str);
  frequencia(str, tam);
}

void exercicio2() {
  char frase1[tam2], frase2[tam2];

  printf("Digite uma frase:\n");

  frase1[strlen(frase1) - 1] = '\0';
  fflush(stdin);
  for (int i = 0; i < tam2; i++) {
    if (frase1[i] == 't' && frase1[i + 1] == 'e' && frase1[i + 2] == 'c' &&
        frase1[i + 3] == 'l' && frase1[i + 4] == 'a' && frase1[i + 5] == 'd' &&
        frase1[i + 6] == 'o') {
      for (int j = 0; j < i + 8; j++) {
        frase2[j] = frase1[j];
      }
      strcat(frase2, "ou mouse");
    }

    for (int a = i + 9; a < strlen(frase1); a++) {
      frase2[strlen(frase2)] = frase1[a];
    }
  }
  printf("Nova frase: %s", frase2);
}

void exercicio3() {
  char frase[tam3], novaFrase[tam3], *x, *y;

  printf("Digite uma frase:\n");
  fgets(frase, sizeof(frase), stdin);

  // fflush(stdin);

  frase[strcmp(frase, "\n")] = '\0';

  x = strtok(frase, " ");
  y = strtok(frase, " ");
  while (x != NULL && y != NULL) {
    if (strcmp(x, "aluno") == 0) {
      strcat(novaFrase, "estudante");
    } else if (strcmp(y, "escola") == 0) {
      strcat(novaFrase, "universidade");
    } else {
      strcat(novaFrase, x);
    }
  }

  printf("A nova frase: %s\n", novaFrase);
}

int main() {

  int exercicio = 0;
  char final;

  do {
    printf("Selecione o exercecício (1 - 3): \n");

    scanf("%d", &exercicio);
    switch (exercicio) {
    case 1:
      exercicio1();
      break;

    case 2:
      exercicio2();
      break;

    case 3:
      exercicio3();
      break;

    default:
      printf("Digite uma opção valida\n");
    }
    printf("Deseja continuar (s ou n): \n");
    scanf(" %c", &final);

  } while (final == 's');
}