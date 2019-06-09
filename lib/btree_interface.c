#include "btree_interface.h"

/* int is_bt_insert(char* cmd) {
	return (strcmp(cmd, "insert") == 0) || 
			(strcmp(cmd, "-in") == 0);
}

BTree* get_bt_insert(GenTree* gt, BTree *bt) {
	int cod, cod_par, t;
	char geo_fig[50];
	scanf("%d/%d/%s%d", &cod, &cod_par, geo_fig, &t);
	TFIGURA *f = get_geofig(geo_fig);
	if(!f) {
		printf("Error: Figura geométrica inválida.\n");
	} else {
		gt = _create_node_gt(gt, cod, cod_par, f);
        bt = insert(bt, gt, t);
	}
	return bt;
} */

int is_bt_search(char* cmd) {
	return (strcmp(cmd, "search") == 0) ||
			(strcmp(cmd, "-s") == 0);
}

BTree* get_bt_search(BTree *t) {
	int cod;
	scanf("%d", &cod);
	BTree *node = find(t, cod);
	if(node) {
		print(node, 0);
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
	print(t, 0); 
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
	scanf("Digite o caminho do arquivo: %s", path);
	t = load_gt(t, path);
	return t;
}

BTree* get_bt_convert(BTree* bt) {
    GenTree* gt = new_gt();
    gt = get_gt_load_for_convert(gt);
    int t = 0;
    scanf("%d", &t);
	printf("Convertendo...\n");
    if(gt){
        bt = convert_2_b_tree(gt, bt, t);
        printf("Coversão realizada com sucesso!");
    } 
    else printf("Falha durante a conversão!");
	return bt;
}

BTree* btree_cmds(BTree* bt) {
	char cmd[50];
	scanf("%s", cmd);

	//if(is_bt_insert(cmd))  return get_bt_insert(gt, bt);
	if(is_bt_search(cmd))  return get_bt_search(bt);
	if(is_bt_print(cmd))   return get_bt_print(bt);
	if(is_bt_destroy(cmd)) return get_bt_destroy(bt);
	if(is_bt_convert(cmd)) return get_bt_convert(bt);
	printf("Error: operação não encontrada para BTree!\n");
	return bt;
}

int is_bt_cmd(char* cmd) {
	return (strcmp(cmd, "btree") == 0) || 
			(strcmp(cmd, "bt") == 0);
}
