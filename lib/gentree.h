#ifndef GENTREE_H
#define GENTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "figuras.h"

// Nó da arvore genérica, possui como informação figuras geométricas
typedef struct gentree {
	int cod; // codigo unico do nó da arvore
	int cod_parent;
	TFIGURA* geofig; // a informação do nó, ou seja, a figura geométrica
	struct gentree *child, *brother; // nós filho e irmão
} GenTree;

typedef struct gentree GenTree;
GenTree* new_gt(void);
GenTree* insert_gt(GenTree* t, int cod_geo, int cod_parent, TFIGURA* geofig);
GenTree* search_gt(GenTree* t, int cod);
GenTree* remove_gt(GenTree* t, int cod);
void print_gt(GenTree *t);
void print_gt_keys(GenTree *t);
void free_gt(GenTree* t);
GenTree* load_gt(GenTree *t, char* path);
void save_gt(GenTree *t, char* path);
GenTree* edit_gt(GenTree* t, int cod);
TFIGURA* get_geofig(char* tipo);
GenTree* copy_gt_node(GenTree* t);

#endif