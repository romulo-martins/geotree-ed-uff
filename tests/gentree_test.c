#include "../lib/gentree.h"

// Interface dos testes
GenTree* gentree_factory(void);
void insert_test(void);
void search_test(void);
void remove_test(void);

// Main dos testes
int main(int argc, char const *argv[]) {
	insert_test();
	search_test();
	remove_test();

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
	t = insert_gt(t, 1, 0, "TRI");
	t = insert_gt(t, 2, 1, "RET");
	t = insert_gt(t, 3, 1, "TRA");
	t = insert_gt(t, 4, 1, "CIR");
	t = insert_gt(t, 5, 4, "QUA");
	t = insert_gt(t, 6, 2, "RET");
	t = insert_gt(t, 7, 5, "TRA");
	t = insert_gt(t, 8, 5, "CIR");
	t = insert_gt(t, 9, 4, "QUA");
	t = insert_gt(t, 10, 1, "TRI");
	return t;	
}

// Realiza os testes de buscas
void search_test(void) {
	printf("\nTeste de buscas ...\n");

	GenTree *t = gentree_factory();
	if(search_gt(t, 4)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 9)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 2)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 3)) printf("OK\n"); else printf("ERROR\n");
	
	free_gt(t);
}

// Realiza os testes de inserção
void insert_test(void) {
	printf("\nTeste de inserção ...\n");

	GenTree *t = gentree_factory();
	t = insert_gt(t, 12, 0, "RET"); // insere novo elemento na raiz
	t = insert_gt(t, 13, 6, "RET");
	t = insert_gt(t, 14, 6, "CIR");
	t = insert_gt(t, 15, 7, "QUA");
	t = insert_gt(t, 16, 7, "TRI");
	if(search_gt(t, 12)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 13)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 14)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 15)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 16)) printf("OK\n"); else printf("ERROR\n");

	free_gt(t);
}

// Realiza os testes de remoção
void remove_test(void) {
	printf("\nTeste de remoção ...\n");
	
	GenTree *t = gentree_factory();
	t = remove_gt(t, 1); // remove da raiz
	if(!search_gt(t, 1)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 2)) printf("OK\n"); else printf("ERROR\n");

	t = remove_gt(t, 2); // remove da nova raiz
	if(!search_gt(t, 2)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 6)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 3)) printf("OK\n"); else printf("ERROR\n");

	t = remove_gt(t, 5);
	if(!search_gt(t, 5)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 4)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 7)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 9)) printf("OK\n"); else printf("ERROR\n");

	t = remove_gt(t, 3);
	if(!search_gt(t, 3)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 6)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 4)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 7)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 9)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 8)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 10)) printf("OK\n"); else printf("ERROR\n");

	free_gt(t);
}