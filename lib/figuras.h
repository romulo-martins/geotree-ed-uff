#ifndef FIGURAS_H
#define FIGURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "areas.h"

// Definindo estrutura genérica para as figuras geométricas
typedef struct figura {
	char tipo[3];
	int dim, base_menor, base_maior, altura;
	float area;
} TFIGURA;

// Definindo tipo das figuras
#define CIRCULO "CIR"
#define QUADRADO "QUA"
#define RETANGULO "RET"
#define TRAPEZIO "TRA"
#define TRIANGULO "TRI"

TFIGURA* criar_circulo(char* tipo, int raio);
TFIGURA* criar_quadrado(char* tipo, int lado);
TFIGURA* criar_triangulo(char* tipo, int base, int altura);
TFIGURA* criar_retangulo(char* tipo, int base, int altura);
TFIGURA* criar_trapezio(char* tipo, int base_menor, int base_maior, int altura);
void print_figura(TFIGURA* f);
char* figura_to_str(TFIGURA* f);
TFIGURA* editar_no(TFIGURA* f);

#endif