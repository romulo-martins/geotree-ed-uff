#include "../lib/gentree.h"

// Interface dos testes
GenTree* gentree_factory(void);
void search_test(GenTree *t);
void insert_test(GenTree *t);
void remove_test(GenTree *t);

int main(int argc, char const *argv[]) {
	GenTree *t = gentree_factory();

	print_gt(t);
	
	search_test(t);
	insert_test(t);
	remove_test(t);

	free_gt(t);

	return 0;
}

/*
Exemplo (apenas código):
	  1
	 /
	2 - 3 - 4 - 10
   /       /
  6	      5 - 9
         /  
        7 - 8

Saida (apenas código):
1
--2
----6
--3
--4
----5
------7
------8
----9
--10
*/
GenTree* gentree_factory(void) {
	GenTree *t = new_gt();
	t = insert_gt(t, 1, 0, "TRI", NULL);
	t = insert_gt(t, 2, 1, "RET", NULL);
	t = insert_gt(t, 3, 1, "TRA", NULL);
	t = insert_gt(t, 4, 1, "CIR", NULL);
	t = insert_gt(t, 5, 4, "QUA", NULL);
	t = insert_gt(t, 6, 2, "RET", NULL);
	t = insert_gt(t, 7, 5, "TRA", NULL);
	t = insert_gt(t, 8, 5, "CIR", NULL);
	t = insert_gt(t, 9, 4, "QUA", NULL);
	t = insert_gt(t, 10, 1, "TRI", NULL);
	return t;	
}

// Realiza o teste de buscas
void search_test(GenTree *t) {
	printf("\nTeste de buscas ... \n");
	GenTree *gt = search_gt(t, 4);
	if(gt && (strcmp(gt->type, "CIR") == 0)) printf("OK\n"); else printf("ERROR\n");
	gt = search_gt(t, 9);
	if(gt && (strcmp(gt->type, "QUA") == 0)) printf("OK\n"); else printf("ERROR\n");
	gt = search_gt(t, 2);
	if(gt && (strcmp(gt->type, "RET") == 0)) printf("OK\n"); else printf("ERROR\n");
	gt = search_gt(t, 3);
	if(gt && (strcmp(gt->type, "TRA") == 0)) printf("OK\n"); else printf("ERROR\n");
}

void insert_test(GenTree *t) {
	printf("\nTeste de inserção ... TODO\n");
}

void remove_test(GenTree *t) {
	printf("\nTeste de remoção ... TODO\n");
}