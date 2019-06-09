#include "gentree_interface.h"

int is_gt_insert(char* cmd) {
	return (strcmp(cmd, "insert") == 0) || 
			(strcmp(cmd, "-in") == 0);
}

GenTree* get_gt_insert(GenTree* t) {
	int cod, cod_par;
	char geo_fig[50];
	scanf("%d/%d/%s", &cod, &cod_par, geo_fig);
	TFIGURA *f = get_geofig(geo_fig);
	if(!f) {
		printf("Error: Figura geométrica inválida.\n");
	} else {
		t = insert_gt(t, cod, cod_par, f);
	}
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
	int cod;
	scanf("%d", &cod);
	GenTree *node = search_gt(t, cod);
	if(node) {
		printf(" %d (%d) ", node->cod, node->cod_parent);
		print_figura(node->geofig);
	} else {
		printf("Error: figura não encontrada.\n");
	}
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
			(strcmp(cmd, "-c") == 0);
}

int is_gt_edit(char* cmd){
	return (strcmp(cmd, "edit") == 0) || (strcmp(cmd, "-e") == 0);
}

GenTree* get_gt_convert(GenTree *t) {
	printf("TODO: Conversão\n"); // TODO: fazer a conversão
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
	char cmd[50];
	scanf("%s", cmd);

	if(is_gt_insert(cmd))  return get_gt_insert(t);
	if(is_gt_remove(cmd))  return get_gt_remove(t);
	if(is_gt_search(cmd))  return get_gt_search(t);
	if(is_gt_print(cmd))   return get_gt_print(t);
	if(is_gt_destroy(cmd)) return get_gt_destroy(t);
	if(is_gt_convert(cmd)) return get_gt_convert(t);
	if(is_gt_load(cmd))    return get_gt_load(t);
	if(is_gt_edit(cmd))	   return get_gt_edit(t);
	printf("Error: operação não encontrada para GenTree!\n");
	return t;
}

int is_gt_cmd(char* cmd) {
	return (strcmp(cmd, "gentree") == 0) || 
			(strcmp(cmd, "gt") == 0);
}