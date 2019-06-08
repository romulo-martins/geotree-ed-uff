/*
Realiza testes das operações básicas da árvore, sem levar em consideração as figuras geométricas.
*/

#include "../lib/avl.h"

// Interface dos testes
TAVL* avl_factory(void);
void insere_test(void);
void busca_test(void);

// Main dos testes
int main (int argc, char const *argv[]){
	insere_test();
	busca_test();

	return 0;

}

/* Exemplo (apenas código):
50 25 10 5 7 3 30 20 8 15


Saída (apenas código):
			10 
			   \
		   /  	\
		  /    	 \
		 7       25
		/ \	   /    \
	   5   8  /      \
	 / 		 20      50
	3	    /		/
		   /	   /  
		 15      30
*/

TAVL* avl_factory(void){
	TAVL *a = inicializa_avl();
	a = insere_no_avl(a, 50, NULL);
	a = insere_no_avl(a, 25, NULL);
	a = insere_no_avl(a, 10, NULL);
	a = insere_no_avl(a, 5, NULL);
	a = insere_no_avl(a, 7, NULL);
	a = insere_no_avl(a, 3, NULL);
	a = insere_no_avl(a, 30, NULL);
	a = insere_no_avl(a, 20, NULL);
	a = insere_no_avl(a, 8, NULL);
	a = insere_no_avl(a, 15, NULL);

	return a;
}

//Realiza testes de busca
void busca_test(void){
	printf("\n Teste de buscas ...\n");

	TAVL *a = avl_factory();
	if(busca_avl(a, 10))  printf("OK\n"); else printf("ERROR\n");
	if(busca_avl(a, 7))   printf("OK\n"); else printf("ERROR\n");
	if(busca_avl(a, 3))   printf("OK\n"); else printf("ERROR\n");
	if(busca_avl(a, 20))  printf("OK\n"); else printf("ERROR\n");
	if(busca_avl(a, 8))   printf("OK\n"); else printf("ERROR\n");
	if(busca_avl(a, 15))  printf("OK\n"); else printf("ERROR\n");

	libera_arvore_avl(a);
}

void insere_test(void){
	printf("\n Teste de inserção... \n");

	TAVL *a = avl_factory();
	a = insere_no_avl(a, 12, NULL);
	a = insere_no_avl(a, 13, NULL);
	a = insere_no_avl(a, 14, NULL);
	a = insere_no_avl(a, 15, NULL);
	a = insere_no_avl(a, 16, NULL);

	if(busca_avl(a, 12))  printf("OK\n"); else printf("ERROR\n");
	if(busca_avl(a, 13))  printf("OK\n"); else printf("ERROR\n");
	if(busca_avl(a, 14))  printf("OK\n"); else printf("ERROR\n");
	if(busca_avl(a, 15))  printf("OK\n"); else printf("ERROR\n");
	if(busca_avl(a, 16))  printf("OK\n"); else printf("ERROR\n");

	//libera_arvore_avl(a);
}

void remove_test(void){
	printf("Testes de remoção...\n");

	TAVL *a = avl_factory();
	a = retira_no_avl(a, 10); //Remove a raiz
	if(!busca_avl(a, 10)) printf("OK\n"); else printf("ERROR\n");
	if(busca_avl(a, 7)) printf("OK\n"); else printf("ERROR\n");
}