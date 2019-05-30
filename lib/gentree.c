#include "gentree.h"

/*
 +=====================================+
 | Arvore Genérica (Generic Tree - GT) |
 +=====================================+
*/


GenTree* new_gt(void) {
	return NULL;
}


GenTree* _create_node_gt(int cod, int cod_parent, void* geofig) {
	GenTree *node = (GenTree*) malloc(sizeof(GenTree));
	node->cod = cod;
	node->cod_parent = cod_parent;
	node->geofig = geofig;
	node->child = NULL;
	node->brother = NULL;
	return node;
}


GenTree* insert_gt(GenTree* t, int cod, int cod_parent, void* geofig) {
	if(search_gt(t, cod)) {
		printf("Error: um elemento de codigo %d já existe, informe um outro código.\n", cod);
		return t;	
	} 

	GenTree *node = _create_node_gt(cod, cod_parent, geofig); // novo nó a ser inserido
	if(cod_parent == 0) { // insere o elemento na raiz
		node->cod_parent = 0;
		if(t) {
			t->cod_parent = node->cod;
			node->child = t;
		}
		return node;
	} 

	GenTree *parent = search_gt(t, cod_parent);
	if(!parent) { // não encontrou o pai informado, não faz nada
		printf("Error: o pai informado, de codigo %d, não foi encontrado.\n", cod_parent);
		return t;	
	}
	
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


void _parent_to_child(GenTree *parent, GenTree *child) {
	if(!child) return;

	if(!parent->child) { // não possui outro filho, associa o novo filho
		parent->child = child;
	} else { // já possui filhos, torna o novo filho irmão do ultimo filho 
		GenTree *last = parent->child; 
		while(last->brother) last = last->brother;
		last->brother = child;
	}

	GenTree *curr = child;
	while(curr) { // altera o código do novo filho e irmãos
		curr->cod_parent = parent->cod;
		curr = curr->brother;
	}
}


GenTree* _remove_root(GenTree *t) {
	GenTree *temp = t;
	if(t->child) {
		GenTree *brother = t->child->brother;
		t = t->child;
		t->cod_parent = 0;
		t->brother = NULL;
		if(brother) {
			_parent_to_child(t, brother);
		}
	}
	free(temp);
	return t;
}


GenTree* remove_gt(GenTree* t, int cod) {
	GenTree *node = search_gt(t, cod);
	if(!node) {
		printf("Error: o elemento de código %d não existe na arvore.\n", cod);
		return t;
	}
	if(node->cod_parent == 0) return _remove_root(t);

	GenTree *parent = search_gt(t, node->cod_parent);
	GenTree *curr = parent->child, *prev = NULL;

	while((curr->brother) && (curr->cod != cod)) { // busca o nó na lista de irmãos
		prev = curr;
		curr = curr->brother;
	}

	if(!prev) { // neste caso é o primeiro filho na lista de filhos.
		parent->child = node->brother;
		_parent_to_child(parent, node->child);
		free(node);
		return t;
	} 

	prev->brother = curr->brother; // neste caso é algum irmão do primeiro filho.
	_parent_to_child(parent, curr->child);
	free(curr);
	return t;
}


void print_2d(GenTree *t, int count, int wfigs) {
	if(t) {
		for (int i = 0; i < count; i++) printf("---");
		printf(" %d (%d) ", t->cod, t->cod_parent);
		if(wfigs) print_figura(t->geofig); else printf("\n");
		print_2d(t->child, count+1, wfigs);
		print_2d(t->brother, count, wfigs);
	}
}

void print_gt_wfigs(GenTree *t) {
	print_2d(t, 0, 1);
}


void print_gt(GenTree *t) {
	print_2d(t, 0, 0);
}


void free_gt(GenTree* t) {
	if(t) {
		free_gt(t->brother);
		free_gt(t->child);
		free(t);
	}
}
