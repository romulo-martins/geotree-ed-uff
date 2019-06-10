#include "btree_interface.h"

int is_bt_search(char* cmd) {
	return (strcmp(cmd, "search") == 0) ||
			(strcmp(cmd, "-s") == 0);
}

BTree* get_bt_search(BTree *t) {
	int cod;
	scanf("%d", &cod);
	BTree *node = find(t, cod);
	if(node) {
        print_figure(cod, node);
	} else {
		printf("Error: figura não encontrada.\n");
	}
	return t;
}

int is_bt_print(char* cmd) {
	return (strcmp(cmd, "print") == 0) || 
			(strcmp(cmd, "-p") == 0);
}

BTree* get_bt_print(BTree *t) {
    if (t) print(t, 0); 
    else printf("Arvore vazia!");
	return t;
}

int is_bt_destroy(char* cmd) {
	return (strcmp(cmd, "destroy") == 0) ||
			(strcmp(cmd, "-d") == 0);
}

BTree* get_bt_destroy(BTree* t) {
	free_bt(t);
	return NULL;
}

int is_bt_convert(char* cmd) {
	return (strcmp(cmd, "convert") == 0) ||
			(strcmp(cmd, "-c") == 0);
}

int is_gt_load_for_convert(char* cmd) {
	return (strcmp(cmd, "load") == 0) ||
			(strcmp(cmd, "-l") == 0);
}

GenTree* get_gt_load_for_convert(GenTree* t) {
	char path[100];
	scanf("%s", path);
	t = load_gt(t, path);
	return t;
}

BTree* convert_from_file(void){
    GenTree* gt = new_gt();
    gt = get_gt_load_for_convert(gt);
    BTree* bt = new_bt();
    int t = 0;
    scanf("%d", &t);
    if (t == 0){
        printf("O parametro t não pode ser igual a 0");
        return bt;
    }
	printf("Convertendo...\n");
    if(gt){
        bt = convert_2_b_tree(gt, bt, t);
        printf("Coversão realizada com sucesso!");
    } 
    else printf("Falha durante a conversão!");
	return bt;
}

BTree* convert_from_memory(GenTree* gt) {
    BTree* bt = new_bt();
    int t = 0;
    scanf("%d", &t);
    if (t == 0){
        printf("O parametro t não pode ser igual a 0");
        return bt;
    }
	printf("Convertendo...\n");
    if(gt){
        bt = convert_2_b_tree(gt, bt, t);
        printf("Coversão realizada com sucesso!");
    } 
    else printf("Falha durante a conversão!");
	return bt;
}

BTree* get_bt_convert(GenTree* gt) {
    if(!gt) return convert_from_file();
    return convert_from_memory(gt);
}

BTree* btree_cmds(GenTree* gt, BTree* bt) {
	char cmd[50];
	scanf("%s", cmd);

	if(is_bt_search(cmd))  return get_bt_search(bt);
	if(is_bt_print(cmd))   return get_bt_print(bt);
	if(is_bt_destroy(cmd)) return get_bt_destroy(bt);
	if(is_bt_convert(cmd)) return get_bt_convert(gt);
	printf("Error: operação não encontrada para BTree!\n");
	return bt;
}

int is_bt_cmd(char* cmd) {
	return (strcmp(cmd, "btree") == 0) || 
			(strcmp(cmd, "bt") == 0);
}
