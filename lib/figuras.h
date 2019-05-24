#ifndef FIGURAS_H
#define FIGURAS_H


#include "figuras.h"



// Definindo estrutura genérica para as figuras geométricas
typedef struct figura {
	int codigo;
	char tipo[3];
	float dim, base_menor, base_maior, altura;
	float area;
} TFIGURA;

/* Cria um nó */
TFIGURA* criar_no(int codigo, char* tipo, float dim, float base_menor, float base_maior, float altura);

#endif