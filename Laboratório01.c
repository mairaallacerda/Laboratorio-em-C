#include <math.h>
#include <stdio.h>

int dobro() {
  int num;

  printf("Digite um numero para ser calculado o dobro\n");
  scanf("%d", &num);
  printf("O dobro do numero digitado e %d\n", num * 2);
  return num * 2;
}

int som() {

  int soma, num1, num2;

  printf("Digite um numero para que seja somado\n");
  scanf("%d", &num1);

  printf("Digite outro numero para que seja somado\n");
  scanf("%d", &num2);

  soma = num1 + num2;

  printf("O dobro do numero digitado e %d\n", soma);
  return soma;
}

int qua() {

  double num, quadrado;

  printf("Digite um numero para que se ache o seu quadrado\n");
  scanf("%lf", &num);

  quadrado = num * num;

  printf("O quadrado do numero digitado e %.20f\n", quadrado);
  return quadrado = num * num;
}

int raiz() {

  double num, raiz;

  printf("Digite um numero para que ache sua raiz\n");
  scanf("%lf", &num);

  raiz = sqrt(num);

  printf("A raiz do numero digitado e %.20f\n", raiz);

  return raiz;
}

int main() {

  dobro();
  som();
  qua();
  raiz();
}
