/*
Arquivo que contém as funções de criação para cada tipo de nó
*/

#include "figuras.h"

//Definindo tipos de modificações
#define FIGURA 0
#define DIMENSAO 1


/* Cria as figuras de acordo com o tipo informado na entrada */
// Cria um nó definindo a partir do tipo
TFIGURA* criar_no(char* tipo, int dim, int base_menor, int base_maior, int altura){

	if(!strcmp(tipo, CIRCULO))  return criar_circulo(CIRCULO, dim);
	if(!strcmp(tipo, QUADRADO)) return criar_quadrado(QUADRADO, dim);
	if(!strcmp(tipo, TRIANGULO))return criar_triangulo(TRIANGULO, base_menor, altura);
	if(!strcmp(tipo, RETANGULO))return criar_retangulo(RETANGULO, base_menor, altura);
	if(!strcmp(tipo, TRAPEZIO)) return criar_trapezio(TRAPEZIO, base_menor, base_maior, altura);

	printf("Tipo informado não existe.\n");
	exit(1);
}

// Círculo
TFIGURA* criar_circulo(char* tipo, int raio){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->dim = raio;
	novo->area = area_circulo(raio);
	return novo;
}

// Quadrado
TFIGURA* criar_quadrado(char* tipo, int lado){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->dim = lado;
	novo->area = area_quadrado(lado);
	return novo;
}


// Triângulo
TFIGURA* criar_triangulo(char* tipo, int base, int altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->base_menor = base;
	novo->altura = altura;
	novo->area = area_triangulo(base, altura);
	return novo;
}


// Retângulo
TFIGURA* criar_retangulo(char* tipo, int base, int altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->base_menor = base;
	novo->altura = altura;
	novo->area = area_retangulo(base, altura);
	return novo;
}

// Trapézio
TFIGURA* criar_trapezio(char* tipo, int base_menor, int base_maior, int altura){
	TFIGURA *novo = (TFIGURA*) malloc(sizeof(TFIGURA));
	strcpy(novo->tipo, tipo);
	novo->base_menor = base_menor;
	novo->base_maior = base_maior;
	novo->altura = altura;
	novo->area = area_trapezio(base_menor, base_maior, altura);
	return novo;
}

void print_figura(TFIGURA* f) {
	if(!strcmp(f->tipo, CIRCULO)) printf("[%s %d %.2f]\n",f->tipo, f->dim, f->area); 
	if(!strcmp(f->tipo, QUADRADO)) printf("[%s %d %.2f]\n",f->tipo, f->dim, f->area); 
	if(!strcmp(f->tipo, TRIANGULO)) printf("[%s %d %d %.2f]\n",f->tipo, f->base_menor, f->altura, f->area); 
	if(!strcmp(f->tipo, RETANGULO)) printf("[%s %d %d %.2f]\n",f->tipo, f->base_menor, f->altura, f->area); 
	if(!strcmp(f->tipo, TRAPEZIO)) printf("[%s %d %d %d %.2f]\n",f->tipo, f->base_menor, f->base_maior, f->altura, f->area);
}

// To String: Converte o struct de figura para uma string
char* figura_to_str(TFIGURA* f) {
	char *str = (char*)malloc(sizeof(char) * 32);
	if(!strcmp(f->tipo, CIRCULO)) sprintf(str, "%s %d", f->tipo, f->dim); 
	if(!strcmp(f->tipo, QUADRADO)) sprintf(str, "%s %d", f->tipo, f->dim);
	if(!strcmp(f->tipo, TRIANGULO)) sprintf(str, "%s %d %d", f->tipo, f->base_menor, f->altura);
	if(!strcmp(f->tipo, RETANGULO)) sprintf(str, "%s %d %d", f->tipo, f->base_menor, f->altura);
	if(!strcmp(f->tipo, TRAPEZIO)) sprintf(str, "%s %d %d %d", f->tipo, f->base_menor, f->base_maior, f->altura);
	return str;
}

/* Funções de edição para cada figura*/

//Editar raio e área do círculo
TFIGURA* editar_circulo(char* tipo, TFIGURA *f){
	int raio;
	strcpy(f->tipo, tipo);
	printf("Digite o raio do círculo\n");
	scanf("%d", &raio);
	f->dim = raio;
	f->area = area_circulo(raio);
	return f;
}

//Editar lado e área do quadrado
TFIGURA* editar_quadrado(char* tipo, TFIGURA *f){
	int lado;
	strcpy(f->tipo, tipo);
	printf("Digite o lado do quadrado\n");
	scanf("%d", &lado);
	f->dim = lado;
	f->area = area_quadrado(lado);
	return f;
}

//Editar base, altura e área do triângulo
TFIGURA* editar_triangulo(char* tipo, TFIGURA *f){
	int base, altura;
	strcpy(f->tipo, tipo);
	printf("Digite a base e altura do triângulo nessa ordem\n");
	scanf("%d %d", &base, &altura);
	f->base_menor = base;
	f->altura = altura;
	f->area = area_triangulo(base, altura);
	return f;
}

//Editar base menor, base maior, altura e área do trapézio
TFIGURA* editar_trapezio(char* tipo, TFIGURA *f){
	int base_menor, base_maior, altura;
	strcpy(f->tipo, tipo);
	printf("Digite a base menor, a base maior e a altura do trapézio nessa ordem\n");
	scanf("%d %d %d", &base_menor, &base_maior, &altura);
	f->base_menor = base_menor;
	f->base_maior = base_maior;
	f->altura = altura;
	f->area = area_trapezio(base_menor, base_maior, altura);
	return f;
}

//Editar base, altura e área do retângulo
TFIGURA* editar_retangulo(char* tipo, TFIGURA *f){
	int base, altura;
	strcpy(f->tipo, tipo);
	printf("Digite a base e a altura do retângulo nessa ordem\n");
	scanf("%d %d", &base, &altura);
	f->base_menor = base;
	f->altura = altura;
	f->area = area_retangulo(base, altura);
	return f;
}

//Apenas alterações nas dimensões da figura
TFIGURA* editar_dimensoes_figura(char* tipo, TFIGURA *f){
	if(!strcmp(tipo, CIRCULO))  return editar_circulo(CIRCULO, f);
	if(!strcmp(tipo, QUADRADO)) return editar_quadrado(QUADRADO, f);
	if(!strcmp(tipo, TRIANGULO))return editar_triangulo(TRIANGULO, f);
	if(!strcmp(tipo, RETANGULO))return editar_retangulo(RETANGULO, f);
	if(!strcmp(tipo, TRAPEZIO)) return editar_trapezio(TRAPEZIO, f);

	printf("Valor inválido.\n");

	return f;
}

//Caso o usuário deseje trocar de figura
TFIGURA* editar_figura(TFIGURA *f){
	char tipo[3];
	printf("Qual o tipo da figura?\n");
	printf("        [CIR para círculo.]        \n");
	printf("        [QUA para quadrado.]       \n");
	printf("        [RET para retângulo.]      \n");
	printf("        [TRA para trapézio.]       \n");
	printf("        [TRI para triângulo.]      \n");
	printf("\n");

	scanf(" %s", tipo);
	
	return editar_dimensoes_figura(tipo, f);
}

TFIGURA* editar_no(TFIGURA* f){
	int modificacao;
	printf("O que deseja modificar? 0 - trocar a figura. 1 - alterar dimensões da figura\n");
	scanf("%d", &modificacao);
	print_figura(f);
	if(modificacao == FIGURA){
		return editar_figura(f);
	} else if(modificacao == DIMENSAO){
		return editar_dimensoes_figura(f->tipo, f);
	} 
	
	printf("Valor inválido");
	return f;
}

TFIGURA* copia_figura(TFIGURA* f) {
	return criar_no(f->tipo, f->dim, f->base_menor, f->base_maior, f->altura);
}