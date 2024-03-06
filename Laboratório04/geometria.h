#ifndef GEOMETRIA_H
#define GEOMETRIA_H

float peri_qua(float baseQuadrado);
float area_qua(float baseQuadrado);
float peri_ret(float alturaRetangulo, float baseRetangulo);
float area_ret(float alturaRetangulo, float baseRetangulo);
float peri_circulo(float raioCirculo);
float area_circulo(float raioCirculo);
float peri_tri(float baseTriangulo);
float area_tri(float alturaTriangulo, float baseTriangulo);
float peri_trap(float baseTrapezio, float baseMenorTrapezio, float lado1, float lado2);
float area_trap(float baseTrapezio, float baseMenorTrapezio, float alturaTrapezio);

#endif