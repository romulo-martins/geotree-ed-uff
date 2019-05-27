#include "../lib/gentree.h"

// Interface dos testes
GenTree* gentree_factory(void);
void search_test(GenTree *t);
void insert_test(GenTree *t);
void remove_test(GenTree *t);

int main(int argc, char const *argv[]) {
	GenTree *t = gentree_factory();
	insert_test(t);
	search_test(t);
	// remove_test(t);
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
void search_test(GenTree *t) {
	printf("\nTeste de buscas ...\n");

	if(search_gt(t, 4)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 9)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 2)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 3)) printf("OK\n"); else printf("ERROR\n");
}

// Realiza os testes de inserção
void insert_test(GenTree *t) {
	printf("\nTeste de inserção ...\n");

	t = insert_gt(t, 12, 0, "RET"); // insere novo elemento na raiz
	t = insert_gt(t, 13, 6, "RET");
	t = insert_gt(t, 14, 6, "CIR");
	t = insert_gt(t, 15, 3, "QUA");
	t = insert_gt(t, 16, 3, "TRI");
	if(search_gt(t, 12)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 13)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 14)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 15)) printf("OK\n"); else printf("ERROR\n");
	if(search_gt(t, 16)) printf("OK\n"); else printf("ERROR\n");
}

// Realiza os testes de remoção
void remove_test(GenTree *t) {
	printf("\nTeste de remoção ...\n");

	// TODO: falta tratar remoção na raiz
	// t = remove_gt(t, 1);
	// if(!search_gt(t, 1)) printf("OK\n"); else printf("ERROR\n");
	// if(search_gt(t, 2)) printf("OK\n"); else printf("ERROR\n");

	t = remove_gt(t, 2);
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
}