#include "btree.h"
#include <stdio.h>

/*
 +=====================================+
 | Arvore B (B Tree - BT) |
 +=====================================+
*/
BTree *new_bt(void) {
    return NULL;
}

BTree *create(int t) {
    BTree *node = (BTree *)malloc(sizeof(BTree));
    node->t = t;
    node->leaf = 1;
    node->nkeys = 0;
    node->gentree_nodes = (GenTree **)malloc(sizeof(GenTree *) * ((2 * t) - 1));
    node->childs = (BTree **)malloc(sizeof(BTree *) * (2 * t));
    for (int i = 0; i < ((2 * t) - 1); i++)
        node->gentree_nodes[i] = NULL;
    for (int i = 0; i < 2 * t; i++)
        node->childs[i] = NULL;
    return node;
}

BTree *find(BTree *tree, int key) {
    if (!tree)
        return tree;
    int i = 0;
    while ((i < tree->nkeys) && (key > tree->gentree_nodes[i]->cod)) {
        i++;
    }
    if ((i < tree->nkeys) && (key == tree->gentree_nodes[i]->cod))
        return tree;
    if (tree->leaf)
        return NULL;
    return find(tree->childs[i], key);
}

void print(BTree *tree, int level) {
    if (tree) {
        int i, j;
        for (i = 0; i < tree->nkeys; i++) {
            print(tree->childs[i], level + 1);
            for (j = 0; j <= level; j++)
                printf("    ");
            if (i == 0) printf("-|%d|\n", tree->gentree_nodes[i]->cod);
            else printf(" |%d|\n", tree->gentree_nodes[i]->cod);
        }
        print(tree->childs[i], level + 1);
    }
}

void free_bt(BTree *tree) {
    if (tree) {
        if (!tree->leaf) {
            int i;
            for (i = 0; i <= tree->nkeys; i++){
                if(i < tree->nkeys) free(tree->gentree_nodes[i]);
                free_bt(tree->childs[i]);
            }
        }
        free(tree->gentree_nodes);
        free(tree->childs);
        free(tree);
    }
}

BTree *split(BTree *x, BTree *y, int i, int t) {
    BTree *z = create(t);
    z->nkeys = t - 1;
    z->leaf = y->leaf;
    for (int j = 0; j < t - 1; j++)
        z->gentree_nodes[j] = y->gentree_nodes[j + t]; //copia as chaves de y depois da chave do meio para z
    if (!y->leaf) {
        for (int j = 0; j < t; j++) {
            z->childs[j] = y->childs[j + t]; //copia os filhos depois da chave do meio para z
            y->childs[j + t] = NULL;
        }
    }
    y->nkeys = t - 1; //atualiza o numero de chaves de y para a primeira metade de y
    for (int j = x->nkeys; j >= i; j--)
        x->childs[j + 1] = x->childs[j]; //como o no tera um novo filho, cria espaço para novo filho
    x->childs[i] = z;                    //faz z ser filho do novo nó
    for (int j = x->nkeys; j >= i; j--)
        x->gentree_nodes[j] = x->gentree_nodes[j - 1]; //move todas as chaves maiores que key
    x->gentree_nodes[i - 1] = y->gentree_nodes[t - 1]; //copia a chave do meio de y para x
    x->nkeys++;
    return x;
}

BTree *insert_nonfull(BTree *x, GenTree *node, int t) {
    int i = x->nkeys - 1;
    if (x->leaf) {
        while ((i >= 0) && (node->cod < x->gentree_nodes[i]->cod)) {
            x->gentree_nodes[i + 1] = x->gentree_nodes[i];
            i--;
        }
        x->gentree_nodes[i + 1] = node;
        x->nkeys++;
        return x;
    }
    while ((i >= 0) && (node->cod < x->gentree_nodes[i]->cod))
        i--;
    i++;
    if (x->childs[i]->nkeys == ((2 * t) - 1)) {
        x = split(x, x->childs[i], i + 1, t);
        if (node->cod > x->gentree_nodes[i]->cod)
            i++;
    }
    x->childs[i] = insert_nonfull(x->childs[i], node, t);
    return x;
}

BTree *insert(BTree *tree, GenTree *node, int t) {
    if (find(tree, node->cod))
        return tree;
    if (!tree) {
        tree = create(t);
        tree->gentree_nodes[0] = node;
        tree->nkeys = 1;
        return tree;
    }
    if (tree->nkeys == ((2 * t) - 1)) {
        BTree *new = create(t);
        new->nkeys = 0;
        new->leaf = 0;
        new->childs[0] = tree;
        new = split(new, tree, 1, t);
        new = insert_nonfull(new, node, t);
        return new;
    }
    tree = insert_nonfull(tree, node, t);
    return tree;
}

BTree *convert_2_b_tree(GenTree *gentree, BTree *btree, int t) {
    if (gentree)
    {
        btree = insert(btree, copy_gt_node(gentree), t);
        btree = convert_2_b_tree(gentree->child, btree, t);
        btree = convert_2_b_tree(gentree->brother, btree, t);
    }
    return btree;
}

void print_figure(int code, BTree *btree) {
    BTree *bt = find(btree, code);
    int i = 0;
    while (bt->gentree_nodes[i]->cod != code)
        i++;
    if (bt->gentree_nodes[i]->geofig)
        print_figura(bt->gentree_nodes[i]->geofig);
    else
        printf("Este nó não possui figura associada.\n");
}
