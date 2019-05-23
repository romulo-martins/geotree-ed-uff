#include "gentree.h"

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

	print_gt(t);

	free_gt(t);

	return 0;
}