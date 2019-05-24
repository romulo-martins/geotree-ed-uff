/*
Arquivo que contém as funções de criação para cada tipo de nó
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include "figuras.h"

// Definindo tipo das figuras
#define CIRCULO "CIR"
#define QUADRADO "QUA"
#define RETANGULO "RET"
#define TRAPEZIO "TRA"
#define TRIANGULO "TRI"

TFIGURA* criar_circulo(int codigo, char* tipo, float raio);
TFIGURA* criar_quadrado(int codigo, char* tipo, float lado);
TFIGURA* criar_triangulo(int codigo, char* tipo, float base, float altura);
TFIGURA* criar_retangulo(int codigo, char* tipo, float base, float altura);
TFIGURA* criar_trapezio(int codigo, char* tipo, float base_menor, float base_maior, float altura);

/* Cria as figuras de acordo com o tipo informado na entrada */
// Cria um nó definindo a partir do tipo
TFIGURA* criar_no(int codigo, char* tipo, float dim, float base_menor, float base_maior, float altura){

	if(!strcmp(tipo, CIRCULO))  return criar_circulo(codigo, CIRCULO, dim);
	if(!strcmp(tipo, QUADRADO)) return criar_quadrado(codigo, QUADRADO, dim);
	if(!strcmp(tipo, TRIANGULO))return criar_triangulo(codigo, TRIANGULO, base_menor, altura);
	if(!strcmp(tipo, RETANGULO))return criar_retangulo(codigo, RETANGULO, base_menor, altura);
	if(!strcmp(tipo, TRAPEZIO)) return criar_trapezio(codigo, TRAPEZIO, base_menor, base_maior, altura);

	printf("Tipo informado não existe.\n");
	exit(1);
}

// Círculo
TFIGURA* criar_circulo(int codigo, char* tipo, float raio){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	novo->codigo = codigo;
	strcpy(novo->tipo, tipo);
	novo->dim = raio;
	novo->area = M_PI * pow(raio,2);
	return novo;
}

// Quadrado
TFIGURA* criar_quadrado(int codigo, char* tipo, float lado){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	novo->codigo = codigo;
	strcpy(novo->tipo, tipo);
	novo->dim = lado;
	novo->area = pow(lado, 2);
	return novo;
}


// Triângulo
TFIGURA* criar_triangulo(int codigo, char* tipo, float base, float altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	novo->codigo = codigo;
	strcpy(novo->tipo, tipo);
	novo->base_menor = base;
	novo->altura = altura;
	novo->area = (base*altura)/2;
	return novo;
}


// Retângulo
TFIGURA* criar_retangulo(int codigo, char* tipo, float base, float altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	novo->codigo = codigo;
	strcpy(novo->tipo, tipo);
	novo->base_menor = base;
	novo->altura = altura;
	novo->area = base*altura;
	return novo;
}

// Trapézio
TFIGURA* criar_trapezio(int codigo, char* tipo, float base_menor, float base_maior, float altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	novo->codigo = codigo;
	strcpy(novo->tipo, tipo);
	novo->base_menor = base_menor;
	novo->base_maior = base_maior;
	novo->altura = altura;
	novo->area = ((base_menor + base_maior) * altura)/2;
	return novo;
}