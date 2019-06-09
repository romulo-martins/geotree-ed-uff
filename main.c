#include <stdio.h>
#include "lib/gentree.h"
<<<<<<< HEAD
#include "lib/avl.h"
=======
#include "lib/gentree_interface.h"
>>>>>>> 1715fe64b14780fe6e5250f7bffac5fd7f8590d0

void show_welcome(void) {
	printf("------------------------------------------\n");
	printf(" Bem vindo a programa de arvore genérica. \n");
	printf("         Ajuda: --help ou -h              \n");
	printf("------------------------------------------\n");
	printf("Execute algum comando ...\n");
}

void show_help_opts(void) {
<<<<<<< HEAD
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

int is_gt_insert(char* cmd) {
	return (strcmp(cmd, "insert") == 0) || 
			(strcmp(cmd, "-in") == 0);
}

GenTree* get_gt_insert(GenTree* t) {
	int cod, cod_par;
	char geo_fig[50];
	scanf("%d/%d/%s", &cod, &cod_par, geo_fig);
	TFIGURA *f = get_geofig(geo_fig);

	t = insert_gt(t, cod, cod_par, f);
	return t;
}

int is_gt_remove(char* cmd) {
	return (strcmp(cmd, "remove") == 0)	||
			(strcmp(cmd, "-rm") == 0);
}

GenTree* get_gt_remove(GenTree* t) {
	int cod;
	scanf("%d", &cod);
	t = remove_gt(t, cod);
	return t;
}

int is_gt_search(char* cmd) {
	return (strcmp(cmd, "search") == 0) ||
			(strcmp(cmd, "-s") == 0);
}

GenTree* get_gt_search(GenTree *t) {
	printf("TODO: Busca\n"); // TODO: fazer a busca
	return t;
}

GenTree* get_gt_edit(GenTree *t){
	int cod;
	scanf("%d", &cod);
	return edit_gt(t, cod);
}

int is_gt_print(char* cmd) {
	return (strcmp(cmd, "print") == 0) || 
			(strcmp(cmd, "-p") == 0);
}

GenTree* get_gt_print(GenTree *t) {
	print_gt(t); 
	return t;
}

int is_gt_destroy(char* cmd) {
	return (strcmp(cmd, "destroy") == 0) ||
			(strcmp(cmd, "-d") == 0);
}

GenTree* get_gt_destroy(GenTree* t) {
	free_gt(t);
	return NULL;
}

int is_gt_convert(char* cmd) {
	return (strcmp(cmd, "convert") == 0) ||
			(strcmp(cmd, "-cv") == 0);
}

int is_gt_edit(char* cmd){
	return (strcmp(cmd, "edit") == 0) || (strcmp(cmd, "-e") == 0);
}

int is_gt2avl(char* cmd){
	return strcmp(cmd, "--avl") == 0;
}

int is_gt2btree(char* cmd){
	return strcmp(cmd, "--btree") == 0;
}

void* get_gt_convert(GenTree *t) {
	char tree_type[3];
	scanf("%s", tree_type);
	printf("TODO: Conversão árvore B\n"); // TODO: fazer a conversão árvore B

	if(is_gt2avl){
		TAVL *avl = create_avl();
		avl = convert_2_avl(t, avl);
	} else {
		printf("Error: tipo de conversão não encontrado para GenTree!\n");
	}
	//if(is_gt2btree) return

	return t;
}

int is_gt_load(char* cmd) {
	return (strcmp(cmd, "load") == 0) ||
			(strcmp(cmd, "-l") == 0);
}

GenTree* get_gt_load(GenTree* t) {
	char path[100];
	scanf("%s", path);
	t = load_gt(t, path);
	return t;
}

GenTree* gentree_cmds(GenTree* t) {
	printf("Comandos disponiveis: \n");
	printf("Arvore genérica: gentree | gt <opts>\n");
	printf("Arvore AVL:      avl     |    <opts>\n");
	printf("Arvore B:        btree   | bt <opts>\n");
	printf("Para sair:       exit    | quit\n");
	printf("Exibir as operações das arvores: <opts> = --help | -h \n");
	printf("\n");
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