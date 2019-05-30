#include "lib/gentree.h"

void show_welcome(void) {
	printf("------------------------------------------\n");
	printf(" Bem vindo a programa de arvore genérica. \n");
	printf("         Ajuda: --help ou -h              \n");
	printf("------------------------------------------\n");
	printf("Execute algum comando ...\n");
}

void show_help_opts(void) {
	printf("Operações da arvore genérica: \n");
	printf("gentree [insert (cod)/(cod-parent)/(figure)]\n");
	printf("        [delete (cod)]                      \n");
	printf("        [search (cod)]                      \n");
	printf("        [print]                             \n");
	printf("        [destroy]                           \n");
	printf("        [convert --avl --btree]             \n");
	printf("        [load (path)]                       \n");
	printf("Para sair do programa: exit ou quit\n");
}

GenTree* gentree_cmds(GenTree* t) {
	char cmd[50];
	scanf("%s", cmd);

	if(strcmp(cmd, "insert") == 0) {
		int cod, cod_par;
		scanf("%d/%d", &cod, &cod_par);
		t = insert_gt(t, cod, cod_par, NULL); // TODO: Precisa tratar a figura geométrica.
		return t;
	}  
	if(strcmp(cmd, "delete") == 0) {
		int cod;
		scanf("%d", &cod);
		t = remove_gt(t, cod);
		return t;
	}  
	if(strcmp(cmd, "search") == 0)  printf("TODO: Busca\n"); // TODO: fazer a busca
	if(strcmp(cmd, "print") == 0) {
		print_gt(t);
		return t;
	} 
	if(strcmp(cmd, "destroy") == 0)  {
		free_gt(t);
		return NULL;
	}
	if(strcmp(cmd, "convert") == 0) printf("TODO: Conversão\n"); // TODO: fazer a conversão
	if(strcmp(cmd, "load") == 0) {
		char path[100];
		scanf("%s", path);
		t = load_gt(t, path);
		return t;
	}
	printf("Error: operação não encontrada para GenTree!\n");
	return t;
}

int is_help_cmd(char* cmd) {
	return (strcmp(cmd, "--help") == 0) ||
			(strcmp(cmd, "-h") == 0); 
}

int is_tree_cmd(char* cmd) {
	return (strcmp(cmd, "gentree") == 0);
}

int is_exit(char* cmd) {
	return (strcmp(cmd, "exit") == 0) || 
			(strcmp(cmd, "quit") == 0);
}

int is_a_cmd(char* cmd) {
	return is_tree_cmd(cmd) || is_help_cmd(cmd);
}	

int main(int argc, char const *argv[]) {
	show_welcome();

	GenTree *t = new_gt();

	char comand[50];
	do {
		scanf("%s", comand);
		if(is_exit(comand)) break;
		if(is_a_cmd(comand)) {
			if(is_help_cmd(comand)) show_help_opts();
			if(is_tree_cmd(comand)) {
				t = gentree_cmds(t);
			} 
		} else {
			printf("Error: comando inválido!\n");
		}
		printf("\n");
	} while(1); 

	printf("Fim do programa ...\n");

	free_gt(t);

	return 0;
}