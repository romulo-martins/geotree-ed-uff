#include "../lib/gentree.h"

int main(int argc, char const *argv[]) {
	GenTree *t = new_gt();
	t = load_gt(t, "in/exemplo-AG.txt");
	print_gt(t);

	return 0;
}
