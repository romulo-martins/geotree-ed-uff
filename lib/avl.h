#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nó da arvore AVL, possui como informação figuras geométricas
typedef struct tavl {
	int codigo; // codigo unico do nó da arvore
	void* geofig; // a informação do nó, ou seja, a figura geométrica
	int alt; //altura do nó
	struct tavl *esq, *dir; // nós da esquerda e da direita
} TAVL;

TAVL* insere_no_avl(TAVL *a, int codigo, void *geofig);
TAVL* retira_no_avl(TAVL *a, int x);
void imprime_arvore_avl(TAVL *a);
void libera_arvore_avl(TAVL *a);
TAVL* inicializa_avl(void);
TAVL* busca_avl(TAVL *a, int codigo);

#endif