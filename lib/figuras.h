#ifndef FIGURAS_H
#define FIGURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "areas.h"

// Definindo estrutura genérica para as figuras geométricas
typedef struct figura {
	char tipo[3];
	float dim, base_menor, base_maior, altura;
	float area;
} TFIGURA;

// Definindo tipo das figuras
#define CIRCULO "CIR"
#define QUADRADO "QUA"
#define RETANGULO "RET"
#define TRAPEZIO "TRA"
#define TRIANGULO "TRI"

TFIGURA* criar_circulo(char* tipo, float raio);
TFIGURA* criar_quadrado(char* tipo, float lado);
TFIGURA* criar_triangulo(char* tipo, float base, float altura);
TFIGURA* criar_retangulo(char* tipo, float base, float altura);
TFIGURA* criar_trapezio(char* tipo, float base_menor, float base_maior, float altura);
void print_figura(TFIGURA* f);
TFIGURA* editar_no(TFIGURA* f);

#endif