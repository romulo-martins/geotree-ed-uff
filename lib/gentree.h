#ifndef _GENTREE_H
#define _GENTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Nó da arvore genérica, possui como informação figuras geométricas
typedef struct gentree {
	int cod; // codigo unico do nó da arvore
	int cod_parent;
	void* geofig; // a informação do nó, ou seja, a figura geométrica
	struct gentree *child, *brother; // nós filho e irmão
} GenTree;

typedef struct gentree GenTree;
GenTree* new_gt(void);
GenTree* insert_gt(GenTree* t, int cod_geo, int cod_parent, void* geofig);
GenTree* search_gt(GenTree* t, int cod);
GenTree* remove_gt(GenTree* t, int cod);
void print_gt(GenTree *t);
void free_gt(GenTree* t);

#endif