#include "lib/gentree.h"

#define STR_SIZE 51

int main(int argc, char const *argv[]) {
	GenTree *t = new_gt();

	char str[STR_SIZE];
	FILE *file = fopen("in/exemplo-AG.txt", "r");
	if (file) {
		while(fgets(str, STR_SIZE, file) != NULL) {
			int cod = atoi(strtok(str, "/"));
			int cod_par = atoi(strtok(NULL, "/"));
			char* geo_fig = strtok(NULL, "");
	    	// printf("%d %d %s\n", cod, cod_par, geo_fig);
	    	t = insert_gt(t, cod, cod_par, NULL);
		}
		fclose(file);
	}

	print_gt(t);

	return 0;
}