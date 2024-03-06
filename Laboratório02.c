#include <math.h>
#include <stdio.h>

void media_desvio() {
  float a, b, c, media, dp;

  printf("Digite um número\n");
  scanf("%f", &a);
  printf("Digite um número\n");
  scanf("%f", &b);
  printf("Digite um número\n");
  scanf("%f", &c);

  media = (a + b + c) / 3;
  dp = sqrt(pow(a - media, 2) + pow(b - media, 2) + pow(c - media, 2)) / 3;

  printf("A média dos três números digitados é: %.2f\n", media);
  printf("O desvio padrão dos três números digitados é: %.2f\n", dp);
}

void inequacao() {
  float x, resultado;

  printf("Digite um número\n");
  scanf("%f", &x);

  resultado = (x + 1) / (-2 * x + 3);
  if (resultado <= 0) {
    printf("O número %.2f satisfaz a inequação\n", x);
  } else {
    printf("O número %.2f não satisfaz a inequação\n", x);
  }
}

void funcionarios() {
  int anos, sexo;
  float salario, bonus;

  printf("Sexo do funcionário: [1] Masculino [2] Feminino: ");
  scanf("%d", &sexo);

  printf("Tempo de trabalho (em anos):");
  scanf("%d", &anos);

  printf("Salario:");
  scanf("%f", &salario);

  if (sexo == 1) {

    if (anos > 15) {
      bonus = salario * 0.2;
    } else {
      bonus = 100;
    }

  } else {

    if (anos > 10) {
      bonus = salario * 0.25;
    } else {
      bonus = 100;
    }
  }

  printf("Bonus: %.2f\n", bonus);
}
int main() {
  int continuar = 1;

  do {
    printf("1. Calcular media e desvio\n");
    printf("2. Inequação\n");
    printf("3. Bonus de Natal\n");

    scanf("%d", &continuar);

    switch (continuar) {
    case 1:
      media_desvio();
      break;

    case 2:
      inequacao();
      break;

    case 3:
      funcionarios();
      break;

    default:
      printf("Digite uma opcao valida\n");
    }
  } while (continuar);
}