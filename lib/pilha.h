
#ifndef PILHA_H
#define PILHA_H

#include "gentree.h"

typedef struct no {
	GenTree* info;
	struct no *prox;
} TNO;

typedef struct pilhaLista {
	TNO *prim;
} TP;

//Cria a pilha
TP* criaPilha();

//Verifica se está vazia
int pilhaVazia(TP *p);

//Insere um elemento na pilha
void push(TP *p, GenTree* x);

//Retira um elemento da pilha
GenTree* pop(TP *p);

//Libera a pilha
void liberaPilha(TP *p);

//Imprime a pilha
void imprimePilha(TP *p);

#endif