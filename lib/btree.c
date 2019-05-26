#include "btree.h"

/*
 +=====================================+
 | Arvore B (B Tree - BT) |
 +=====================================+
*/
BTree *new_bt(void){
    return NULL;
}
BTree *create(int t){
    BTree *node = (BTree*)malloc(sizeof(BTree));
    node->leaf = 1;
    node->nkeys = 0;
    node->keys = (int*)malloc(sizeof(int) * ((2*t)-1));
    node->childs = (BTree**)malloc(sizeof(BTree*) * (2*t));
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

/* void print(BTree *tree){
    if(tree){
        int i;
        for(i = 0; i < tree->nkeys; i++){
            if(!tree->leaf) print(tree->childs[i]);
            printf("%d \n", tree->keys[i]);
        }
        if(!tree->leaf) print(tree->childs[i]);
    }
} */

void print(BTree *tree, int level) {
    if(tree){
        int i;
        for (i = 0; i < level; i++) { printf("  "); }


        printf("|");
        for (i = 0; i < tree->nkeys; i++) {
            printf("%d|", tree->keys[i]);

        }
        printf("\n");


        for (i = 0; i <= tree->nkeys; i++) {
            if (!tree->leaf) {
                print(tree->childs[i], level + 1);
            }
        }
    }
   
}

void free_bt(BTree* tree) {
    if(tree->leaf){                 //se for folha da free no nó
        free(tree);
    }else{
        int i = 0;
        while(i < tree->nkeys+1){   //percorre até o ultimo filho
            free_bt(tree->childs[i]);
            i++;
        }
    }
}

BTree *split(BTree *x, BTree *y, int i, int t){
    BTree *z = create(t);
    z->nkeys = t-1;
    
    for(int j = 0; j < t-1; j++) z->keys[j] = y->keys[j+t]; //copia as chaves de y depois da chave do meio para z
    if(!y->leaf){
        for(int j = 0; j < t; j++){
            z->childs[j] = y->childs[j+t];                  //copia os filhos depois da chave do meio para z
            free(y->childs[j+t]);
        } 
    }
    y->nkeys = t-1;                                                             //atualiza o numero de chaves de y para a primeira metade de y
    for(int j = x->nkeys+1; j >= (i+1); j--) x->childs[j+1] = x->childs[j];     //como o no tera um novo filho, cria espaço para novo filho
    x->childs[i+1] = z;                                                 //faz z ser filho do novo nó
    for(int j = (x->nkeys); j >= i; j--) x->keys[j+1] = x->keys[j];     //move todas as chaves maiores que key
    x->keys[i] = y->keys[t-1];                                          //copia a chave do meio de y para x
    x->nkeys++;
    return x;
}

BTree *insert_nonfull(BTree *x, int key, int t){
    int i = x->nkeys-1;
    if(x->leaf){
        while(i >= 0 && key < x->keys[i]){
            x->keys[i+1] = x->keys[i];
            i--;
        }
        x->keys[i+1] = key;
        x->nkeys += 1;
    }else{
        while(i >= 0 && key < x->keys[i]) i--;
        i += 1;
        if(x->childs[i]->nkeys == (2*t)-1){
            x = split(x, x->childs[i], i, t);
            if(key > x->keys[i]) i += 1;
        }
        x->childs[i] = insert_nonfull(x->childs[i], key, t);
    }
    return x;
}

BTree *insert(BTree *tree, int key, int t){
    if(!tree){
        tree = create(t);
        tree->keys[0] = key;
        tree->nkeys++;
        return tree;
    }
    if(tree->nkeys == ((2*t)-1)){
        BTree *new = create(t);
        new->childs[0] = tree;
        new = split(new, tree, 0, t);
        new = insert_nonfull(tree, key, t);
        return new;
    }
    tree = insert_nonfull(tree, key, t);
    return tree;
}

