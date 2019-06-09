#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gentree.h"

// Nó da arvore AVL, possui como informação figuras geométricas
typedef struct tavl {
	int cod; // codigo unico do nó da arvore
	void* geofig; // a informação do nó, ou seja, a figura geométrica
	int alt; //altura do nó
	struct tavl *esq, *dir; // nós da esquerda e da direita
} TAVL;

TAVL* insert_avl(TAVL *a, int codigo, void *geofig);
TAVL* remove_avl(TAVL *a, int x);
void print_avl(TAVL *a);
void free_avl(TAVL *a);
TAVL* create_avl(void);
TAVL* find_avl(TAVL *a, int codigo);
TAVL* convert_2_avl(GenTree *gentree, TAVL *avl);

#endif