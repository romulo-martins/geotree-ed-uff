/*
Arquivo que cont�m as fun��es para o c�lculo das �reas das figuras.
*/

#include <stdio.h>
#include "math.h"


//Calcula a �rea do c�rculo de acordo com o raio informado pelo usu�rio.
float area_circulo(int raio){
	return M_PI * pow(raio,2);
}

//Calcula a �rea do quadrado de acordo com o lado informado pelo usu�rio.
float area_quadrado(int lado){
	return pow(lado, 2);
}

//Calcula a �rea do tri�ngulo de acordo com base e altura informados pelo usu�rio.
float area_triangulo(int base, int altura){
	return (base*altura)/2;
}

//Calcula a �rea do trap�zio de acordo com base menor, base maior e altura informados pelo usu�rio.
float area_trapezio(int base_menor, int base_maior, int altura){
	return ((base_menor + base_maior) * altura)/2;
}

//Calcula a �rea do ret�ngulo de acordo com base e altura informados pelo usu�rio.
float area_retangulo(int base, int altura){
	return base*altura;
}

