#include <stdio.h>
#include "lib/gentree.h"
#include "lib/avl.h"
#include "lib/gentree_interface.h"

void show_welcome(void) {
	printf("------------------------------------------\n");
	printf(" Bem vindo a programa de arvore genérica. \n");
	printf("         Ajuda: --help ou -h              \n");
	printf("------------------------------------------\n");
	printf("Execute algum comando ...\n");
}

void show_help_opts(void) {
	printf("Operações da arvore genérica:                       \n");
	printf("gentree ou gt                                       \n");
	printf("        [insert  ou -in (cod)/(cod-parent)/(figure)]\n");
	printf("        [remove  ou -rm (cod)]                      \n");
	printf("        [search  ou -s (cod)]                       \n");
	printf("        [print   ou -p]                             \n");
	printf("        [destroy ou -d]                             \n");
	printf("        [convert ou -cv --avl --btree]              \n");
	printf("        [load    ou -l (path)]                      \n");
	printf("        [edit    ou -e (cod)]                       \n");
	printf("Para sair do programa: exit ou quit                 \n");
}


int is_gt2avl(char* cmd){
	return strcmp(cmd, "--avl") == 0;
}

int is_gt2btree(char* cmd){
	return strcmp(cmd, "--btree") == 0;
}

int is_help_cmd(char* cmd) {
	return (strcmp(cmd, "--help") == 0) ||
			(strcmp(cmd, "-h") == 0); 
}

int is_exit(char* cmd) {
	return (strcmp(cmd, "exit") == 0) || 
			(strcmp(cmd, "quit") == 0);
}

int is_a_cmd(char* cmd) {
	return is_gt_cmd(cmd) || is_help_cmd(cmd);
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
			if(is_gt_cmd(comand)) t = gentree_cmds(t);
		} else {
			printf("Error: comando inválido!\n");
		}
		setbuf(stdin, NULL);
		printf("\n");
	} while(1); 

	printf("Fim do programa ...\n");
	free_gt(t);

	return 0;
}