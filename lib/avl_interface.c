#include "avl_interface.h"

int is_avl_help(char* cmd) {
	return (strcmp(cmd, "--help") == 0) ||
			(strcmp(cmd, "-h") == 0); 
}

void get_avl_help(void) {
	printf("Operações da arvore AVL:                       				\n");
	printf("avl ou at                                       			\n");
	printf("        [insert  ou -in <cod>/<figure>]                     \n");
	printf("        [search  ou -s <cod>]                       		\n");
	printf("        [print   ou -p]                             		\n");
	printf("        [destroy ou -d]                             		\n");
	printf("        [convert ou -c <path> se for por arquivo]			\n");
	printf("        [convert ou -c se for por instância em memória]		\n");
	printf("\n");
}

int is_avl_search(char* cmd) {
	return (strcmp(cmd, "search") == 0) ||
			(strcmp(cmd, "-s") == 0);
}

AVL* get_avl_search(AVL *t) {
	int cod;
	scanf("%d", &cod);
	AVL *node = avl_find(t, cod);
	if(node) {
        print_figura(node->geofig);
	} else {
		printf("Error: figura não encontrada.\n");
	}
	return t;
}

int is_avl_print(char* cmd) {
	return (strcmp(cmd, "print") == 0) || 
			(strcmp(cmd, "-p") == 0);
}

AVL* get_avl_print(AVL *t) {
    if (t) avl_print(t); 
    else printf("Arvore vazia!");
	return t;
}

int is_avl_destroy(char* cmd) {
	return (strcmp(cmd, "destroy") == 0) ||
			(strcmp(cmd, "-d") == 0);
}

AVL* get_avl_destroy(AVL* t) {
	free_avl(t);
	return NULL;
}

int is_avl_convert(char* cmd) {
	return (strcmp(cmd, "convert") == 0) ||
			(strcmp(cmd, "-c") == 0);
}

int is_avl_load_for_convert(char* cmd) {
	return (strcmp(cmd, "load") == 0) ||
			(strcmp(cmd, "-l") == 0);
}

int is_avl_insert(char* cmd) {
	return (strcmp(cmd, "insert") == 0) ||
			(strcmp(cmd, "-in") == 0);
}

GenTree* get_gt_load_for_convert_avl(GenTree* t) {
	char path[100];
	scanf("%s", path);
	t = load_gt(t, path);
	return t;
}

AVL* convert_avl_from_file(void){
    GenTree* gt = new_gt();
    gt = get_gt_load_for_convert_avl(gt);
    AVL* at = new_avl();
	printf("Convertendo...\n");
    if(gt){
        at = convert_2_avl(gt, at);
        printf("Coversão realizada com sucesso!");
    } 
    else printf("Falha durante a conversão!");
	return at;
}

AVL* convert_avl_from_memory(GenTree* gt) {
    AVL* at = new_avl();
	printf("Convertendo...\n");
    if(gt){
        at = convert_2_avl(gt, at);
        printf("Coversão realizada com sucesso!");
    } 
    else printf("Falha durante a conversão!");
	return at;
}

AVL* get_avl_convert(GenTree* gt) {
    if(!gt) return convert_avl_from_file();
    return convert_avl_from_memory(gt);
}

AVL* get_avl_insert(AVL* at) {
	int cod, cod_par;
	char geo_fig[50];
	scanf("%d/%s", &cod, geo_fig);
	TFIGURA *f = get_geofig(geo_fig);
	if(!f) {
		printf("Error: Figura geométrica inválida.\n");
	} else {
		at = insert_avl(at, cod, f);
	}
    return at;
}

AVL* avl_cmds(GenTree* gt, AVL* at) {
	char cmd[50];
	scanf("%s", cmd);

	if(is_avl_help(cmd)) {
		get_avl_help();
		return at;
	}

	if(is_avl_search(cmd))  return get_avl_search(at);
	if(is_avl_print(cmd))   return get_avl_print(at);
	if(is_avl_destroy(cmd)) return get_avl_destroy(at);
	if(is_avl_convert(cmd)) return get_avl_convert(gt);
	if(is_avl_insert(cmd))	return get_avl_insert(at);
	printf("Error: operação não encontrada para AVL!\n");
	return at;
}

int is_avl_cmd(char* cmd) {
	return (strcmp(cmd, "avl") == 0) || 
			(strcmp(cmd, "at") == 0);
}
