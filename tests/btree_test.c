#include "../lib/btree.h"

int main(int argc, char const *argv[]){
    BTree *b_tree = new_bt();
    b_tree = insert(b_tree, 10, 2);
    b_tree = insert(b_tree, 20, 2);
    b_tree = insert(b_tree, 15, 2);
    b_tree = insert(b_tree, 1, 2);
    b_tree = insert(b_tree, 5, 2);
    b_tree = insert(b_tree, 11, 2);
    b_tree = insert(b_tree, 12, 2);
    b_tree = insert(b_tree, 16, 2);
    b_tree = insert(b_tree, 17, 2);
    b_tree = insert(b_tree, 21, 2);

    print(b_tree, 0);

    if(find(b_tree, 20)) printf("OK\n"); else printf("ERRO\n");
    free_bt(b_tree);
}