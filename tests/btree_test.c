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
    /* b_tree = insert(b_tree, 10, 2);
    b_tree = insert(b_tree, 20, 2);
    b_tree = insert(b_tree, 15, 2);
    b_tree = insert(b_tree, 1, 2);
    b_tree = insert(b_tree, 5, 2);
    b_tree = insert(b_tree, 11, 2);
    b_tree = insert(b_tree, 12, 2);
    b_tree = insert(b_tree, 16, 2);
    b_tree = insert(b_tree, 17, 2);
    b_tree = insert(b_tree, 21, 2); */

    print(b_tree, 0);
    print_figure(10, b_tree);
    print_figure(1, b_tree);

    if(find(b_tree, 10)) printf("OK\n"); else printf("ERRO\n");
    /*if(find(b_tree, 15)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 20)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 1)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 5)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 11)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 12)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 16)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 17)) printf("OK\n"); else printf("ERRO\n");
    if(find(b_tree, 21)) printf("OK\n"); else printf("ERRO\n");
    if(!find(b_tree, 24)) printf("OK\n"); else printf("ERRO\n");// não deve encotrar */
    free_bt(b_tree);
}