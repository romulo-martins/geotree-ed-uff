#include "../lib/gentree.h"

int main(int argc, char const *argv[]) {
	GenTree *t = new_gt();
	t = load_gt(t, "in/exemplo.txt");
	save_gt(t, "out/teste.txt");
	print_gt(t);

	return 0;
}
