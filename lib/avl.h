#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gentree.h"

// Nó da arvore AVL, possui como informação figuras geométricas
typedef struct tavl {
	int cod; // codigo unico do nó da arvore
	TFIGURA* geofig; // a informação do nó, ou seja, a figura geométrica
	int alt; //altura do nó
	struct tavl *esq, *dir; // nós da esquerda e da direita
} AVL;

AVL* new_avl(void);
AVL* insert_avl(AVL *a, int codigo, TFIGURA *geofig);
AVL* avl_find(AVL *a, int codigo);
AVL* remove_avl(AVL *a, int x);
void avl_print(AVL *a);
void free_avl(AVL *a);
AVL* convert_2_avl(GenTree *gentree, AVL *avl);
void print_avl_figure(int cod, AVL *at);

#endif