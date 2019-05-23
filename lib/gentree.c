#include "gentree.h"

/*
 +=====================================+
 | Arvore Genérica (Generic Tree - GT) |
 +=====================================+
*/

#define CIRCLE = "CIR"
#define SQUARE = "QUA"
#define RECTANGLE = "RET"
#define TRAPEZE = "TRA"
#define TRIANGLE = "TRI"

GenTree* new_gt(void) {
	return NULL;
}

GenTree *create_node_gt(int cod, char* type, void* geofig) {
	GenTree *node = (GenTree*) malloc(sizeof(GenTree));
	node->cod = cod;
	node->type = type;
	node->geofig = geofig;
	node->child = NULL;
	node->brother = NULL;
	return node;
}

GenTree* insert_gt(GenTree* t, int cod_geo, int cod_parent, char* type, void* geofig) {
	GenTree *node = create_node_gt(cod_geo, type, geofig); // novo nó a ser inserido

	if(!t || !cod_parent) return node; // insere primeiro elemento

	GenTree *parent = search_gt(t, cod_parent);

	if(!parent) return t; // não encontrou nenhum pai, não faz nada
	
	if(!parent->child) {
		parent->child = node;
	} else {
		GenTree *child = parent->child;
		while(child->brother) child = child->brother; // pega o ultimo nó filho
		child->brother = node; // associa ao ultimo irmão do pai em comum
	}

	return t;
}

GenTree* search_gt(GenTree* t, int cod) {
	if(!t) return NULL;
	if(t->cod == cod) return t;
	GenTree *brother = search_gt(t->brother, cod);
	if(brother) return brother;
	return search_gt(t->child, cod);
}

GenTree* remove_gt(GenTree* t, int cod) {
	// TODO:
	return NULL;
}

void print_2d(GenTree *t, int count) {
	if(t) {
		for (int i = 0; i < count; i++) printf("----");
		printf("%d %s\n", t->cod, t->type);
		print_2d(t->brother, count);
		print_2d(t->child, ++count);
	}
}

void print_gt(GenTree *t) {
	print_2d(t, 0);
}

void free_gt(GenTree* t) {
	if(t) {
		free_gt(t->brother);
		free_gt(t->child);
		free(t);
	}
}

void pre_order_gt(GenTree *t) {
	if(t) {
		printf("%d %s \n", t->cod, t->type);
		print_gt(t->brother);
		print_gt(t->child);
	}
}

void in_order_gt(GenTree *t) {
	if(t) {
		print_gt(t->brother);
		printf("%d %s \n", t->cod, t->type);
		print_gt(t->child);
	}
}

void post_order_gt(GenTree *t) {
	if(t) {
		print_gt(t->brother);
		print_gt(t->child);
		printf("%d %s \n", t->cod, t->type);
	}
}