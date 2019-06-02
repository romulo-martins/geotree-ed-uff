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

GenTree* edit_gt(GenTree* t, int cod){
	GenTree* node = search_gt(t, cod);
	if(!node){
		 printf("Nó não encontrado.");
		return NULL;
	}
	printf("Figura selecionada: \n");
	printf("Código: %d ", cod);
	print_figura(node->geofig);
	node->geofig = editar_no(node->geofig);
	return node;
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
		if(brother) _parent_to_child(t, brother);
		free(temp);
		return t;
	}
	free(t);
	return NULL;
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

TFIGURA* get_geofig(char* tipo){
	float dim, base_menor, base_maior, altura; 
	if(!strcmp(tipo, CIRCULO)) {
		dim = atoi(strtok(NULL, " "));
		return criar_circulo(CIRCULO, dim);	
	} 
	if(!strcmp(tipo, QUADRADO)) {
		dim = atoi(strtok(NULL, " "));
		return criar_quadrado(QUADRADO, dim);	
	} 
	if(!strcmp(tipo, TRIANGULO)) {
		base_menor = atoi(strtok(NULL, " "));
		altura = atoi(strtok(NULL, " "));
		return criar_triangulo(TRIANGULO, base_menor, altura);
	}
	if(!strcmp(tipo, RETANGULO)) {
		base_menor = atoi(strtok(NULL, " "));
		altura = atoi(strtok(NULL, " "));
		return criar_retangulo(RETANGULO, base_menor, altura);
	}
	if(!strcmp(tipo, TRAPEZIO)) {
		base_menor = atoi(strtok(NULL, " "));
		base_maior = atoi(strtok(NULL, " "));
		altura = atoi(strtok(NULL, " "));
		return criar_trapezio(TRAPEZIO, base_menor, base_maior, altura);
	}

	return NULL;
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
	if (!t) {
		printf("Error: arvore vazia!\n");
		return;
	}
	print_2d(t, 0, 1);
}


void free_gt(GenTree* t) {
	if(t) {
		free_gt(t->brother);
		free_gt(t->child);
		free(t);
	}
}

/*
Carrega um arquivo .txt com os elementos a ser inseridos na arvore genérica.
O arquivo deve possuir o seguinte formato: 
(codigo unico da figura)/(código do pai)/(tipo da figura e suas dimensoes)

Exemplo:
	1/0/TRI 3 2
	2/1/CIR 4
	3/2/RET 2 2
	etc ...
*/
GenTree* load_gt(GenTree *t, char* path) {
	int str_size = 51; // cada linha possui entre 10 a 13 caracteres, mas joguei 50 só pra garantir 
	char str[str_size]; 
	
	FILE *file = fopen(path, "r");
	if (file) {
		while(fgets(str, str_size, file) != NULL) {
			int cod = atoi(strtok(str, "/"));
			int cod_par = atoi(strtok(NULL, "/"));
			char* geo_fig = strtok(NULL, " "); // falta tratar a figura geométrica
			TFIGURA* f = get_geofig(geo_fig);
	    	t = insert_gt(t, cod, cod_par, f);
		}
		fclose(file);
	} else {
		printf("Error: arquivo não encontrado!\n");
	}
	return t;
}
