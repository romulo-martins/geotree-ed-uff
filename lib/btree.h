#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct b_tree{
    int nkeys, leaf, *keys; //número de chaves, informa se é folha, vetor de chaves
    struct b_tree **childs; //ponteiro para o filho
}BTree;

typedef struct b_tree BTree;

BTree *find(BTree *tree, int k);
BTree *create(int t);
void print(BTree *tree);
BTree *insert(BTree *tree, int key, int t);
void free_bt(BTree *tree);
BTree *split(BTree *tree, int i, int t);
BTree *insert_nonfull(BTree *tree, int key, int t);