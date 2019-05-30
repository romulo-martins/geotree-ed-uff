/*
Arquivo que contém as funções de necessárias para implementar uma árvore AVL
*/

#include "avl.h"
#include "figuras.h"

TAVL* inicializa_avl(void);
int maior(int altura_esq, int altura_dir);
TAVL* rotacao_direita(TAVL *d);
TAVL* rotacao_esquerda(TAVL *e);
int altura_arvore_avl(TAVL *a);
int maior(int altura_esq, int altura_dir);
int calcula_balanceamento(TAVL *a);
TAVL* cria_no_avl(int codigo, void* geofig);
void imprime_arvore_avl(TAVL *a, int espaco);


#define COUNT 10


//Função recursiva para adicionar um nó em uma árvore AVL
TAVL* insere_no_avl(TAVL *a, int codigo, void *geofig){

	//Verifica se a árvore está vazia
	if(!a) return cria_no_avl(codigo, geofig);

	if(codigo < a->codigo){
		a->esq = insere_no_avl(a->esq, codigo, a->geofig);	
	} else if(codigo > a->codigo){
		a->dir = insere_no_avl(a->dir, codigo, a->geofig);
	} else {
		return a;
	}

	//Verifica se a (sub)árvore está balanceada.
	int fator_balanceamento = calcula_balanceamento(a);

	//Rotação simples à direita (RSD)
	if(fator_balanceamento > 1 && codigo < a->esq->codigo){
		return rotacao_direita(a);
	}

	//Rotação simples à esquerda (RSE)
	if(fator_balanceamento < -1 && codigo > a->dir->codigo){
		return rotacao_esquerda(a);
	}

	//Rotação dupla esquerda-direita (RED)
	if(fator_balanceamento > 1 && codigo > a->esq->codigo){
		a->esq = rotacao_esquerda(a->esq);
		return rotacao_direita(a);
	}

	//Rotação dupla direita-esquerda (RDE)
	if(fator_balanceamento < -1 && codigo < a->dir->codigo){
		a->dir = rotacao_direita(a->dir);
		return rotacao_esquerda(a);
	}

	return a;
}	

//Performa rotação à direita.
TAVL* rotacao_direita(TAVL *t){
	TAVL *sub_esq = t->esq;
	TAVL *sub_dir = sub_esq->dir;

	sub_esq->dir = t;
	t->esq = sub_dir;

	return sub_esq;
}

//Performa rotação à esquerda.
TAVL* rotacao_esquerda(TAVL *p){
	TAVL *sub_dir = p->dir;
	TAVL *sub_esq = sub_dir->esq;

	sub_dir->esq = p;
	p->dir = sub_esq;

	return sub_dir;
}

// Calcula a altura da árvore AVL
int altura_arvore_avl(TAVL *a){
	if(!a) return -1;
	return maior(altura_arvore_avl(a->esq), altura_arvore_avl(a->dir)) + 1;
}

//Função que retorna a maior altura
int maior(int altura_esq, int altura_dir){
	return (altura_esq > altura_dir) ? altura_esq + 1 : altura_dir + 1;
}

int calcula_balanceamento(TAVL *a){
	if(!a) return 0;
	return altura_arvore_avl(a->esq) - altura_arvore_avl(a->dir);
}

//Cria um nó para a árvore AVL
TAVL* cria_no_avl(int codigo, void* geofig){
	TAVL *novo = (TAVL*) malloc(sizeof(TAVL));
	novo->codigo = codigo;
	novo->geofig = geofig;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

TAVL* inicializa_avl(void){
	return NULL;
}


void imprime_nos_avl(TAVL *a, int espaco) { 
 
    if (a == NULL) 
        return; 

    espaco += COUNT; 
  
    print2DUtil(a->dir, espaco);  
    printf("\n"); 
    for (int i = COUNT; i < espaco; i++) 
        printf(" "); 
    printf("%d\n", a->codigo); 
 
    print2DUtil(a->esq, espaco); 
} 
  
void imprime_arvore_avl(TAVL *a) { 
   imrpime_nos_avl(a, 0); 
} 
