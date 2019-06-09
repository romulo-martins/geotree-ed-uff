#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gentree.h"

typedef struct b_tree{
    int nkeys, leaf; //número de chaves, informa se é folha
    GenTree **keys; //vetor de nós da arvore generica
    struct b_tree **childs; //ponteiro para o filho
}BTree;

typedef struct b_tree BTree;

BTree *find(BTree *tree, int k);
BTree *create(int t);
void print(BTree *tree, int level);
BTree *insert(BTree *tree, GenTree *node, int t);
void free_bt(BTree *tree);
BTree *split(BTree *x, BTree *y, int i, int t);
BTree *insert_nonfull(BTree *tree, GenTree *node, int t);
BTree *new_bt(void);
BTree *convert_2_b_tree(GenTree *gentree, BTree *btree, int t);
void print_figure(int code, BTree *btree);