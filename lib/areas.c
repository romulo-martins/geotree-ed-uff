/*
Arquivo que contém as funções para o cálculo das áreas das figuras.
*/

#include <stdio.h>
#include "math.h"


//Calcula a área do círculo de acordo com o raio informado pelo usuário.
float area_circulo(int raio){
	return M_PI * pow(raio,2);
}

//Calcula a área do quadrado de acordo com o lado informado pelo usuário.
float area_quadrado(int lado){
	return pow(lado, 2);
}

//Calcula a área do triângulo de acordo com base e altura informados pelo usuário.
float area_triangulo(int base, int altura){
	return (base*altura)/2;
}

//Calcula a área do trapézio de acordo com base menor, base maior e altura informados pelo usuário.
float area_trapezio(int base_menor, int base_maior, int altura){
	return ((base_menor + base_maior) * altura)/2;
}

//Calcula a área do retângulo de acordo com base e altura informados pelo usuário.
float area_retangulo(int base, int altura){
	return base*altura;
}

