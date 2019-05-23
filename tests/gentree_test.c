#include "../lib/gentree.h"

int main(int argc, char const *argv[]) {
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

	// Verifica se está realizando a impressão de forma correta
	print_gt(t);

	// Realiza o teste de buscas
	GenTree *gt = search_gt(t, 4);
	if(gt && (strcmp(gt->type, "CIR") == 0)) printf("OK\n"); else printf("ERROR\n");
	gt = search_gt(t, 9);
	if(gt && (strcmp(gt->type, "QUA") == 0)) printf("OK\n"); else printf("ERROR\n");
	gt = search_gt(t, 2);
	if(gt && (strcmp(gt->type, "RET") == 0)) printf("OK\n"); else printf("ERROR\n");
	gt = search_gt(t, 3);
	if(gt && (strcmp(gt->type, "TRA") == 0)) printf("OK\n"); else printf("ERROR\n");

	free_gt(t);

	return 0;
}