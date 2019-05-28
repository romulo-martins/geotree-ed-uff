/*
Arquivo que contém as funções de criação para cada tipo de nó
*/

#include "figuras.h"

/* Cria as figuras de acordo com o tipo informado na entrada */
// Cria um nó definindo a partir do tipo
TFIGURA* criar_no(char* tipo, float dim, float base_menor, float base_maior, float altura){

	if(!strcmp(tipo, CIRCULO))  return criar_circulo(CIRCULO, dim);
	if(!strcmp(tipo, QUADRADO)) return criar_quadrado(QUADRADO, dim);
	if(!strcmp(tipo, TRIANGULO))return criar_triangulo(TRIANGULO, base_menor, altura);
	if(!strcmp(tipo, RETANGULO))return criar_retangulo(RETANGULO, base_menor, altura);
	if(!strcmp(tipo, TRAPEZIO)) return criar_trapezio(TRAPEZIO, base_menor, base_maior, altura);

	printf("Tipo informado não existe.\n");
	exit(1);
}

// Círculo
TFIGURA* criar_circulo(char* tipo, float raio){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->dim = raio;
	novo->area = M_PI * pow(raio,2);
	return novo;
}

// Quadrado
TFIGURA* criar_quadrado(char* tipo, float lado){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->dim = lado;
	novo->area = pow(lado, 2);
	return novo;
}


// Triângulo
TFIGURA* criar_triangulo(char* tipo, float base, float altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->base_menor = base;
	novo->altura = altura;
	novo->area = (base*altura)/2;
	return novo;
}


// Retângulo
TFIGURA* criar_retangulo(char* tipo, float base, float altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->base_menor = base;
	novo->altura = altura;
	novo->area = base*altura;
	return novo;
}

// Trapézio
TFIGURA* criar_trapezio(char* tipo, float base_menor, float base_maior, float altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->base_menor = base_menor;
	novo->base_maior = base_maior;
	novo->altura = altura;
	novo->area = ((base_menor + base_maior) * altura)/2;
	return novo;
}

void print_figura(TFIGURA* f) {
	if(!strcmp(f->tipo, CIRCULO)) printf("[%s %.2f]\n",f->tipo, f->dim); 
	if(!strcmp(f->tipo, QUADRADO)) printf("[%s %.2f]\n",f->tipo, f->dim); 
	if(!strcmp(f->tipo, TRIANGULO)) printf("[%s %.2f %.2f]\n",f->tipo, f->base_menor, f->altura); 
	if(!strcmp(f->tipo, RETANGULO)) printf("[%s %.2f %.2f]\n",f->tipo, f->base_menor, f->altura); 
	if(!strcmp(f->tipo, TRAPEZIO)) printf("[%s %.2f %.2f %.2f]\n",f->tipo, f->base_menor, f->base_maior, f->altura);
}