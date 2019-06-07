
#include "pilha.h"

int MAX_TAM = 100;

TP* criaPilha(){
	TP *p = (TP *) malloc(sizeof(TP));
	p->prim = NULL;
	return p;
}

int pilhaVazia(TP *p){
	return p->prim == NULL;
}

void push(TP *p, GenTree* x){
	TNO *no = (TNO *) malloc(sizeof(TNO));
	no->info = x;
	no->prox = p->prim;
	p->prim = no;
}

GenTree* pop(TP *p){
	if(pilhaVazia(p)) exit(1);
	void *elemento = p->prim->info;
	TNO *q = p->prim;
	p->prim = q->prox;
	free(q);
	return elemento;
}

void liberaPilha(TP *p){
	TNO *q = p->prim, *t;
	while(!pilhaVazia(p)){
		t = q;
		q = q->prox;
		free(t);
	}
	free(q);
}