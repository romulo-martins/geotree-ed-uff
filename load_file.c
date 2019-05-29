#include "lib/gentree.h"

GenTree* load_gt(GenTree *t, char* path);

int main(int argc, char const *argv[]) {
	GenTree *t = new_gt();
	t = load_gt(t, "in/exemplo-AG.txt");
	print_gt(t);

	return 0;
}

/*
Carrega um arquivo txt com os elementos a ser inseridos na arvore genérica.

O arquivo possui o seguinte formato: 
(codigo unico da figura)/(código do pai)/(tipo da figura e suas dimensoes)

Exemplo:
	1/0/TRI 3 2
	2/1/CIR 4
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
			char* geo_fig = strtok(NULL, ""); // falta tratar a figura geométrica
	    	// printf("%d %d %s\n", cod, cod_par, geo_fig);
	    	t = insert_gt(t, cod, cod_par, NULL);
		}
		fclose(file);
	}
	return t;
}