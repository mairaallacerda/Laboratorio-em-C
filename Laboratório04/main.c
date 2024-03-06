#include "geometria.h"
#include <stdio.h>

void area() {

  float baseQuadrado, baseRetangulo, alturaRetangulo, raioCirculo,
      alturaTriangulo, baseTriangulo, baseTrapezio, baseMenorTrapezio,
      alturaTrapezio;

  printf("Digite a base do quadrado:");
  scanf("%f", &baseQuadrado);
  printf("Área do quadrado: %.2f\n", area_qua(baseQuadrado));

  printf("Digite a base e altura do retângulo:");
  scanf("%f %f", &baseRetangulo, &alturaRetangulo);
  printf("Área do retângulo: %.2f\n", area_ret(baseRetangulo, alturaRetangulo));

  printf("Digite o raio do círculo: ");
  scanf("%f", &raioCirculo);
  printf("Área do círculo: %.2f\n", area_circulo(raioCirculo));

  printf("Digite a base e altura do triângulo:");
  scanf("%f %f", &baseTriangulo, &alturaTriangulo);
  printf("Área do Triângulo: %.2f\n", area_tri(baseTriangulo, alturaTriangulo));

  printf("Digite a base maior, a base menor e a altura do trapézio:");
  scanf("%f %f %f", &baseTrapezio, &baseMenorTrapezio, &alturaTrapezio);
  printf("Área do Trapézio: %.2f\n",
         area_trap(baseTrapezio, baseMenorTrapezio, alturaTrapezio));
}
void perimetro() {

  float baseQuadrado, baseRetangulo, alturaRetangulo, raioCirculo,
      baseTriangulo, baseTrapezio, baseMenorTrapezio, lado1, lado2;

  printf("Digite a base do quadrado:");
  scanf("%f", &baseQuadrado);
  printf("Área do quadrado: %.2f\n", peri_qua(baseQuadrado));

  printf("Digite a base e altura do retângulo:");
  scanf("%f %f", &baseRetangulo, &alturaRetangulo);
  printf("Área do retângulo: %.2f\n", peri_ret(baseRetangulo, alturaRetangulo));

  printf("Digite o raio do círculo: ");
  scanf("%f", &raioCirculo);
  printf("Área do círculo: %.2f\n", peri_circulo(raioCirculo));

  printf("Digite a base e altura do triângulo:");
  scanf("%f", &baseTriangulo);
  printf("Área do Triângulo: %.2f\n", peri_tri(baseTriangulo));

  printf("Digite a base maior, a base menor, o lado 1 e o lado 2 do trapézio:");
  scanf("%f %f %f %f", &baseTrapezio, &baseMenorTrapezio, &lado1, &lado2);
  printf("Área do Trapézio: %.2f\n",
         peri_trap(baseTrapezio, baseMenorTrapezio, lado1, lado2));
}
int main(void) {
  int continuar = 0;
  char final;
  do {

    printf("Digite 1 para calcular a área ou Digite 2 para calcular o "
           "perímetro \n");

    scanf("%d", &continuar);

    switch (continuar) {
    case 1:
      area();
      break;

    case 2:
      perimetro();

      break;

    default:
      printf("Digite uma opção valida\n");
    }

    printf("Deseja continuar (s ou n): \n");
    scanf(" %c", &final);

  } while (final == 's');
}