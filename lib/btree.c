#include "btree.h"

/*
 +=====================================+
 | Arvore B (B Tree - BT) |
 +=====================================+
*/

BTree *create(int t){
    BTree *node = (BTree*)malloc(sizeof(BTree));
    node->leaf = 1;
    node->nkeys = 0;
    node->keys = (int*)malloc(sizeof(int) * ((2*t)-1));
    node->childs = (BTree*)malloc(sizeof(BTree) * (2*t));
    for(int i = 0; i < 2*t; i++){
        node->childs[i] = NULL;
    }
    return node;
}

BTree *find(BTree *tree, int key){
    if(!tree) return tree;
    int i = 0;
    while((i < tree->nkeys) && (key > tree->keys[i])){
        i++;
    }
    if((i < tree->nkeys) && (key == tree->keys[i])) return tree;
    if(tree->leaf) return NULL;
    return find(tree->childs[i], key);
}

void print(BTree *tree){
    if(tree){
        int i;
        for(i = 0; i < tree->nkeys; i++){
            if(!tree->leaf) print(tree->childs[i]);
            printf("%d \n", tree->keys[i]);
        }
        if(!tree->leaf) print(tree->childs[i]);
    }
}

void free_bt(BTree* tree) {
    if(tree->leaf){ //se for folha da free no nó
        free(tree);
    }else{
        int i = 0;
        while(i < tree->nkeys+1){   //percorre até o ultimo filho
            free_bt(tree->childs[i]);
            i++;
        }
    }
}

BTree *split(BTree *tree, int i, int t){
    BTree *z = (BTree*)malloc(sizeof(BTree));
    BTree *y = tree->childs[i];
    z->leaf = y->leaf;
    z->nkeys = t-1;

    for(int j = 0; j < z->nkeys; j++) z->keys[j] = y->keys[j+t];
    if(!y->leaf){
        for(int j = 0; j < t; j++) z->childs[j] = y->childs[j+t];
    }

    y->nkeys = t-1;
    for(int j = tree->nkeys+1; j >= i+1; j--) tree->childs[j+1] = tree->childs[j];
    
    tree->childs[i+1] = z;
    for(int j = tree->nkeys; j >= i; j--) tree->keys[j+1] = tree->keys[j];
    tree->keys[i] = y->keys[t];
    tree->nkeys = tree->nkeys+1;
    return tree;
}

