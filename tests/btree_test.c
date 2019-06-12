#include "../lib/btree.h"

GenTree* gentree_factory(void) {
	GenTree *t = new_gt();
	t = insert_gt(t, 1, 0, NULL);
	t = insert_gt(t, 2, 1, NULL);
	t = insert_gt(t, 3, 1, NULL);
	t = insert_gt(t, 4, 1, NULL);
	t = insert_gt(t, 5, 4, NULL);
	t = insert_gt(t, 6, 2, NULL);
	t = insert_gt(t, 7, 5, NULL);
	t = insert_gt(t, 8, 5, NULL);
	t = insert_gt(t, 9, 4, NULL);
	t = insert_gt(t, 10, 1, criar_triangulo("TRI", 3, 2));
	return t;	
}

int main(int argc, char const *argv[]){
    BTree *b_tree = create(2);
    GenTree *gentree = gentree_factory();
    b_tree = convert_2_b_tree(gentree, b_tree, 2);

    print(b_tree, 0);
    print_figure(10, b_tree); //encontra e imprime a figura
    print_figure(1, b_tree); //não deve encontrar a figura

    if(find(b_tree, 1)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 2)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 3)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 4)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 5)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 6)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 7)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 8)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 9)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 10)) printf("OK\n"); else printf("ERRO\n");
    if(!find(b_tree, 24)) printf("OK\n"); else printf("ERRO\n");// não deve encontrar
    free_bt(b_tree);
}