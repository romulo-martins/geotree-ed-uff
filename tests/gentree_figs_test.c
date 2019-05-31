#include "../lib/gentree.h"

// Interface dos testes
GenTree* gentree_factory(void);

// Main dos testes
int main(int argc, char const *argv[]) {
	GenTree *t = gentree_factory();
	print_gt(t);
	printf("\n");
	print_gt_wfigs(t);
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
	t = insert_gt(t, 1, 0, criar_triangulo("TRI", 3, 2));
	t = insert_gt(t, 2, 1, criar_retangulo("RET", 3, 3));
	t = insert_gt(t, 3, 1, criar_trapezio("TRA", 2, 3, 4));
	t = insert_gt(t, 4, 1, criar_circulo("CIR", 4));
	t = insert_gt(t, 5, 4, criar_quadrado("QUA", 3));
	t = insert_gt(t, 6, 2, criar_retangulo("RET", 2, 2));
	t = insert_gt(t, 7, 5, criar_trapezio("TRA", 1, 2, 3));
	t = insert_gt(t, 8, 5, criar_circulo("CIR", 2));
	t = insert_gt(t, 9, 4, criar_quadrado("QUA", 1));
	t = insert_gt(t, 10, 1, criar_triangulo("TRI", 1, 2));
	return t;	
}
