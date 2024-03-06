#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM1 10
#define TAM2 4
#define TAM3 4
#define TAM4 4

// fatorial
int fatorial(int x) {

  int fat = 1;

  for (int i = 2; i <= x; i++) {
    fat *= i;
  }

  return fat;
}

// -------------------- EXERCICIO 1 --------------------

void exercicio1() {

  int vet1[TAM1];
  int vet2[TAM1];
  int vetor_resultante[TAM1];

  for (int i = 0; i < TAM1; i++) {
    printf("\nDigite os valores do primiero vetor\n");
    scanf("%d", &vet1[i]);
  }
  for (int i = 0; i < TAM1; i++) {
    printf("\nDigite os valores do segundo vetor\n");
    scanf("%d", &vet2[i]);

    vetor_resultante[i] = vet1[i] * vet2[i];
  }

  printf("\nO vetor resultante da multiplicação é");

  for (int i = 0; i < TAM1; i++) { // ler vetor

    printf(" %d", vetor_resultante[i]);
  }
  printf("\n");
}
// -------------------- EXERCICIO 2 --------------------

void exercicio2() {
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  int vet[n];
  printf("Digite os elementos do vetor:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }

  int max_soma = vet[0];
  int current_sum = vet[0];
  int inicio_indice = 0, final_indice = 0, s = 0;

  for (int i = 1; i < n; i++) {
    if (current_sum + vet[i] > vet[i]) {
      current_sum += vet[i];
    } else {
      current_sum = vet[i];
      s = i;
    }

    if (current_sum > max_soma) {
      max_soma = current_sum;
      inicio_indice = s;
      final_indice = i;
    }
  }

  printf("A soma maxima é %d e o subvetor é {", max_soma);
  for (int i = inicio_indice; i <= final_indice; i++) {
    printf("%d", vet[i]);
    if (i != final_indice)
      printf(",");
  }
  printf("} que começa na posição %d e termina na posição %d\n", inicio_indice,
         final_indice);
}
// -------------------- EXERCICIO 3 --------------------

void exercicio3() {

  int vet1[TAM3], vet2[TAM3], cont = 0;

  for (int i = 0; i < TAM3; i++) {
    printf("\nDigite os valores do primiero vetor\n");
    scanf("%d", &vet1[i]);
  }
  for (int i = 0; i < TAM3; i++) {
    printf("\nDigite os valores do segundo vetor\n");
    scanf("%d", &vet2[i]);
  }

  for (int i = 0; i < TAM3; i++) {
    for (int j = 0; j < TAM3; j++) {
      if (vet1[i] == vet2[j]) {
        cont++;
      }
    }
  }

  if (cont == TAM3) {
    printf("Os vetores são rearranjos um do outro");
  } else {
    printf("Os vetores não são rearranjos um do outro");
  }
}
// -------------------- EXERCICIO 4 --------------------

void exercicio4() {
  int vet1[TAM4], vet2[TAM4], j = TAM4 - 1;
  int produto[TAM4], resultado = 0;

  for (int i = 0; i < TAM4; i++) {
    printf("\nDigite os valores do primiero vetor\n");
    scanf("%d", &vet1[i]);
  }
  for (int i = 0; i < TAM4; i++) {
    printf("\nDigite os valores do segundo vetor\n");
    scanf("%d", &vet2[i]);
  }

  for (int i = 0; i < TAM4; i++) {
    produto[i] = vet1[i] * vet2[j];
    j--;
  }
  for (int i = 0; i < TAM4; i++) {
    resultado += produto[i];
  }
  printf("O resultado é: %d", resultado);
}

// -------------------- EXERCICIO 5 --------------------

void exercicio5() {
  int n, i, x = 0, y = 0;
  printf("Digite o numero de termos\n");
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    x += pow(i, 2);
  }
  y = (n * (n + 1) * ((2 * n) + 1)) / 6;
  if (x == y) {
    printf("\nA igualdade é verdadeira pois %d = %d\n", x, y);
  }
  printf("A soma dos %d primeiros termos da expressão é %d\n", n, x);
  printf("\nO valor da expressão y=(%d*(%d+1)((2%d)+1))/6 é %d", n, n, n, y);
}
// -------------------- EXERCICIO 6 --------------------

void exercicio6() {
  double x, sin_x = 0.0, termo, rad;
  int n = 1, sinal = -1, y;

  printf("Digite um número real x em graus: ");
  scanf("%lf", &x);

  rad = x * 0.0174532;
  rad = x;

  for (int i = 0; i < x; i++) {
    // termo = sin(x);
    termo += sin(x);
    termo = x;

    y = pow(rad, 2 * n - 1) * sinal / fatorial(x);
    sinal *= -1;
    n++;
  }

  if (x == y) {
    printf("\nA igualdade é verdadeira\n");
  } else {
    printf("\nA igualdade não é verdadeira\n");
  }

  printf("sin(x) = %.6f\n", sin(x));

  // printf("sin(x) (math.h) = %.6f\n", sin(rad));
}
// -------------------- EXERCICIO 7 --------------------

void exercicio7() {
  char fim;
  do {
    int num, lin, col, x = 0, lin2, col2, lin3, col3, k = 0, aux = 0;
    int **mat1, **mat2; // ponteiro onde será armazenado
    // int mat3[lin][col2];

    printf("\nInforme o tamanho da matriz A\n");
    scanf("%d %d", &lin, &col);

    // aloca a matriz 1
    mat1 = malloc(lin * sizeof(int *));

    for (int i = 0; i < lin; i++)
      mat1[i] = malloc(col * sizeof(int));

    // Digitar os valores da matriz 1
    for (int i = 0; i < lin; i++) {
      for (int j = 0; j < col; j++) {
        printf("\nDigite o valor da posição [%d][%d]\n", i, j);
        scanf("%d", &x);
        mat1[i][j] = x;
      }
    }

    printf("\nInforme o tamanho da matriz B\n");
    scanf("%d %d", &lin2, &col2);

    // aloca matriz 2
    mat2 = malloc(lin2 * sizeof(int *));

    for (int i = 0; i < lin2; i++)
      mat2[i] = malloc(col2 * sizeof(int));

    int mat3[lin][col2];

    // Digitar os valores da matriz 2
    for (int i = 0; i < lin2; i++) {
      for (int j = 0; j < col2; j++) {
        printf("\nDigite o valor da posição [%d][%d]\n", i, j);
        scanf("%d", &x);
        mat2[i][j] = x;
      }
    }
    printf("---------------------------- Matriz A "
           "---------------------------------\n\n");
    for (int i = 0; i < lin; i++) {
      for (int j = 0; j < col; j++) {
        printf("[%d]", mat1[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    printf("--------------------- Matriz B --------------------------\n\n");

    for (int i = 0; i < lin2; i++) {
      for (int j = 0; j < col2; j++) {
        printf("[%d]", mat2[i][j]);
      }
      printf("\n\n");
    }
    // SOMA
    if (lin == lin2 && col == col2) {
      printf("SOMA\n");
      for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
          mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
      }
      for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
          printf("[%d]", mat3[i][j]);
        }
        printf("\n\n");
      }
    } else {
      printf("\nNão foi possível somar as matrizes\n");
    }
    // DIFERENÇA
    if (lin == lin2 && col == col2) {
      printf("DIFERENÇA\n");
      for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
          mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
      }
      for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
          printf("[%d]", mat3[i][j]);
        }
        printf("\n\n");
      }
    } else {
      printf("\nNão foi possível fazer a diferença das matrizes\n");
    }
    // PRODUTO
    printf("\nPRODUTO\n");
    if (col == lin2) {
      for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col2; j++) {

          mat3[i][j] = 0;
          for (k = 0; k < lin2; k++) {
            aux += mat1[i][k] * mat2[k][j];
          }

          mat3[i][j] = aux;
          aux = 0;
        }
      }
      for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col2; j++) {
          printf("[%d]", mat3[i][j]);
        }
        printf("\n\n");
      }
    } else {
      printf("Não é possível multiplicar as matrizes");
    }
    printf("Deseja continuar (s ou n): \n");
    scanf(" %c", &fim);

  } while (fim != 'n');
}
// -------------------- EXERCICIO 8 --------------------

void exercicio8() {
  char fim;
  do {
    int num, lin, col, x = 0, lin2, col2, lin3, col3, k = 0, aux = 0;
    int **mat1, **mat2; // ponteiro onde será armazenado
    // int mat3[lin][col2];

    printf("\nInforme o tamanho da matriz A\n");
    scanf("%d %d", &lin, &col);

    // aloca a matriz 1
    mat1 = malloc(lin * sizeof(int *));

    for (int i = 0; i < lin; i++)
      mat1[i] = malloc(col * sizeof(int));

    // Digitar os valores da matriz 1
    for (int i = 0; i < lin; i++) {
      for (int j = 0; j < col; j++) {
        printf("\nDigite o valor da posição [%d][%d]\n", i, j);
        scanf("%d", &x);
        mat1[i][j] = x;
      }
    }

    printf("\nInforme o tamanho da matriz B\n");
    scanf("%d %d", &lin2, &col2);

    // aloca matriz 2
    mat2 = malloc(lin2 * sizeof(int *));

    for (int i = 0; i < lin2; i++)
      mat2[i] = malloc(col2 * sizeof(int));

    int mat3[lin][col2];

    // Digitar os valores da matriz 2
    for (int i = 0; i < lin2; i++) {
      for (int j = 0; j < col2; j++) {
        printf("\nDigite o valor da posição [%d][%d]\n", i, j);
        scanf("%d", &x);
        mat2[i][j] = x;
      }
    }

    printf("---------------------------- Matriz A "
           "---------------------------------\n\n");
    for (int i = 0; i < lin; i++) {
      for (int j = 0; j < col; j++) {
        printf("[%d]", mat1[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    printf("--------------------- Matriz B --------------------------\n\n");

    for (int i = 0; i < lin2; i++) {
      for (int j = 0; j < col2; j++) {
        printf("[%d]", mat2[i][j]);
      }
      printf("\n\n");
    }
    // PRODUTO
    printf("\nPRODUTO\n");
    if (col == lin2) {
      for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col2; j++) {

          mat3[i][j] = 0;
          for (k = 0; k < lin2; k++) {
            aux += mat1[i][k] * mat2[k][j];
          }

          mat3[i][j] = aux;
          aux = 0;
        }
      }
      for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col2; j++) {
          printf("[%d]", mat3[i][j]);
        }
        printf("\n\n");
      }
    } else {
      printf("Não é possível multiplicar as matrizes");
    }
    printf("Deseja continuar (s ou n): \n");
    scanf(" %c", &fim);

  } while (fim != 'n');
}
int main() {
  int continuar = 0;
  char final;

  do {
    printf("Selecione o exercecício (1 - 8): \n");

    scanf("%d", &continuar);

    switch (continuar) {
    case 1:
      exercicio1();
      break;

    case 2:
      exercicio2();
      break;

    case 3:
      exercicio3();
      break;

    case 4:
      exercicio4();
      break;

    case 5:
      exercicio5();
      break;

    case 6:
      exercicio6();
      break;
    case 7:
      exercicio7();
      break;
    case 8:
      exercicio8();
      break;

    default:
      printf("Digite uma opção valida\n");
    }

    printf("Deseja continuar (s ou n): \n");
    scanf(" %c", &final);

  } while (final == 's');
}
