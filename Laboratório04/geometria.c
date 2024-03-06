#include "geometria.h"

float peri_qua (float baseQuadrado) {
return 4*baseQuadrado;
}
float area_qua(float baseQuadrado) {
return baseQuadrado*baseQuadrado;
}

float peri_ret(float alturaRetangulo, float baseRetangulo) {
return (alturaRetangulo*2) + (baseRetangulo*2);
}
float area_ret(float alturaRetangulo, float baseRetangulo) {
return alturaRetangulo*baseRetangulo;
}

float peri_circulo(float raioCirculo) {
return (float) 2*3.14*raioCirculo;
}
float area_circulo(float raioCirculo) {
return raioCirculo*raioCirculo*3.14;
}

float peri_tri(float baseTriangulo) {
return baseTriangulo*3;
}
float area_tri(float alturaTriangulo, float baseTriangulo) {
return (baseTriangulo*alturaTriangulo)/2;
}
float peri_trap(float baseTrapezio, float baseMenorTrapezio, float lado1, float lado2) {
return baseTrapezio + baseMenorTrapezio + lado1 + lado2;
}
float area_trap(float baseTrapezio, float baseMenorTrapezio, float alturaTrapezio) {
return (baseTrapezio + baseMenorTrapezio) * alturaTrapezio / 2;
}