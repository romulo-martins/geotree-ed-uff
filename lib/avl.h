#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nó da arvore AVL, possui como informação figuras geométricas
typedef struct tavl {
	int codigo; // codigo unico do nó da arvore
	void* geofig; // a informação do nó, ou seja, a figura geométrica
	struct tavl *esq, *dir; // nós da esquerda e da direita
} TAVL;

TAVL* inicializa_avl(void);
int maior(int altura_esq, int altura_dir);
TAVL* rotacao_direita(TAVL *d);
TAVL* rotacao_esquerda(TAVL *e);
int altura_arvore_avl(TAVL *a);
int maior(int altura_esq, int altura_dir);
int calcula_balanceamento(TAVL *a);
TAVL* cria_no_avl(int codigo, void* geofig);


#endif