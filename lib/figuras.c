/*
Arquivo que contém as funções de criação para cada tipo de nó
*/

#include "figuras.h"

//Definindo tipos de modificações
#define FIGURA 0
#define DIMENSAO 1


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
	novo->area = area_circulo(raio);
	return novo;
}

// Quadrado
TFIGURA* criar_quadrado(char* tipo, float lado){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->dim = lado;
	novo->area = area_quadrado(lado);
	return novo;
}


// Triângulo
TFIGURA* criar_triangulo(char* tipo, float base, float altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->base_menor = base;
	novo->altura = altura;
	novo->area = area_triangulo(base, altura);
	return novo;
}


// Retângulo
TFIGURA* criar_retangulo(char* tipo, float base, float altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->base_menor = base;
	novo->altura = altura;
	novo->area = area_retangulo(base, altura);
	return novo;
}

// Trapézio
TFIGURA* criar_trapezio(char* tipo, float base_menor, float base_maior, float altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->base_menor = base_menor;
	novo->base_maior = base_maior;
	novo->altura = altura;
	novo->area = area_trapezio(base_menor, base_maior, altura);
	return novo;
}

void print_figura(TFIGURA* f) {
	if(!strcmp(f->tipo, CIRCULO)) printf("[%s %.2f %.2f]\n",f->tipo, f->dim, f->area); 
	if(!strcmp(f->tipo, QUADRADO)) printf("[%s %.2f %.2f]\n",f->tipo, f->dim, f->area); 
	if(!strcmp(f->tipo, TRIANGULO)) printf("[%s %.2f %.2f %.2f]\n",f->tipo, f->base_menor, f->altura, f->area); 
	if(!strcmp(f->tipo, RETANGULO)) printf("[%s %.2f %.2f %.2f]\n",f->tipo, f->base_menor, f->altura, f->area); 
	if(!strcmp(f->tipo, TRAPEZIO)) printf("[%s %.2f %.2f %.2f %.2f]\n",f->tipo, f->base_menor, f->base_maior, f->altura, f->area);
}

TFIGURA* editar_no(TFIGURA* f){
	int modificacao;
	printf("O que deseja modificar? 0 - trocar a figura. 1 - alterar dimensões da figura");
	scanf("%d", &modificacao);
	if(modificacao == FIGURA){
		return editar_figura(f);
	} else if(modificacao == DIMENSAO){
		return editar_dimensoes_figura(f->tipo, f);
	} 
	
	printf("Valor inválido");
	return f;
}

TFIGURA* editar_dimensoes_figura(char* tipo, TFIGURA *f){
	if(!strcmp(tipo, CIRCULO))  return editar_circulo(CIRCULO, f);
	if(!strcmp(tipo, QUADRADO)) return editar_quadrado(QUADRADO, f);
	if(!strcmp(tipo, TRIANGULO))return editar_triangulo(TRIANGULO, f);
	if(!strcmp(tipo, RETANGULO))return editar_retangulo(RETANGULO, f);
	if(!strcmp(tipo, TRAPEZIO)) return editar_trapezio(TRAPEZIO, f);
}

TFIGURA* editar_figura(TFIGURA *f){
	char tipo[3];
	printf("Qual o tipo da figura?\n");
	printf("CIR para círculo.\n");
	printf("QUA para quadrado.\n");
	printf("RET para retângulo.\n");
	printf("TRA para trapézio.\n");
	printf("TRI para triângulo.\n");
	
	gets(tipo);
	
	editar_dimensoes_figura(tipo, f);
}


TFIGURA* editar_circulo(char* tipo, TFIGURA *f){
	float raio;
	strcpy(f->tipo, tipo);
	printf("Digite o raio do círculo\n");
	scanf("%f", &raio);
	f->dim = raio;
	f->area = area_circulo(raio);
	return f;
}

TFIGURA* editar_quadrado(char* tipo, TFIGURA *f){
	float lado;
	strcpy(f->tipo, tipo);
	printf("Digite o lado do quadrado\n");
	scanf("%f", &lado);
	f->dim = lado;
	f->area = area_quadrado(lado);
	return f;
}

TFIGURA* editar_triangulo(char* tipo, TFIGURA *f){
	float base, altura;
	strcpy(f->tipo, tipo);
	printf("Digite a base e altura do triângulo nessa ordem\n");
	scanf("%f %f", &base, &altura);
	f->base_menor = base;
	f->altura = altura;
	f->area = area_triangulo(base, altura);
	return f;
}

TFIGURA* editar_trapezio(char* tipo, TFIGURA *f){
	float base_menor, base_maior, altura;
	strcpy(f->tipo, tipo);
	printf("Digite a base menor, a base maior e a altura do trapézio nessa ordem\n");
	scanf("%f %f %f", &base_menor, &base_maior, &altura);
	f->base_menor = base_menor;
	f->base_maior = base_maior;
	f->altura = altura;
	f->area = area_trapezio(base_menor, base_maior, altura);
	return f;
}

TFIGURA* editar_retangulo(char* tipo, TFIGURA *f){
	float base, altura;
	strcpy(f->tipo, tipo);
	printf("Digite a base e a altura do retângulo nessa ordem\n");
	scanf("%f %f", &base, &altura);
	f->base_menor = base;
	f->altura = altura;
	f->area = area_retangulo(base, altura);
	return f;
}
