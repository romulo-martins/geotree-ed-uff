/*
Arquivo que contém as funções de necessárias para implementar uma árvore AVL
*/

#include "avl.h"
#include "figuras.h"

//Libera espaço de memória da árvore
void libera_arvore_avl(TAVL *a){
	if(a != NULL){
		libera_arvore_avl(a->esq);
		libera_arvore_avl(a->dir);
		free(a);
	}
}

//Busca um elemento na árvore de acordo com um código informado
TAVL* busca_avl(TAVL *a, int codigo){
	if(a == NULL) return NULL;
	if(codigo < a->codigo) return busca_avl(a->esq, codigo);
	if(codigo > a->codigo) return busca_avl(a->dir,codigo);
	return a;
}

//Função que retorna a maior altura
int maior(int altura_esq, int altura_dir){
	return (altura_esq > altura_dir) ? altura_esq : altura_dir;
}

// Calcula a altura da árvore AVL
int altura_avl(TAVL *a){
	if(a == NULL) return -1;
	return a->alt;
}


//Performa rotação à direita.
TAVL* rotacao_direita(TAVL *t){
	TAVL *p = NULL;
	p = t->esq;
	t->esq = p->dir;
	p->dir = t;
	t->alt = maior(altura_avl(t->esq), altura_avl(t->dir)) + 1;
	p->alt = maior(altura_avl(p->esq), t->alt) + 1;
	return p;
}

//Performa rotação à esquerda.
TAVL* rotacao_esquerda(TAVL *p){
	TAVL *t;
	t = p->dir;
	p->dir = t->esq;
	t->esq = p;
	p->alt = maior(altura_avl(p->esq), altura_avl(p->dir)) + 1;
	t->alt = maior(altura_avl(t->dir), p->alt) + 1;
	return t;
}

//Performa rotação dupla esquerda-direita (RED)
TAVL* rotacao_esquerda_direita(TAVL* q){
	q->esq = rotacao_esquerda(q->esq);
	return rotacao_direita(q);
}

TAVL* rotacao_direita_esquerda(TAVL * p){
	p->dir = rotacao_direita(p->dir);
	return rotacao_esquerda(p);
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

//Função recursiva para adicionar um nó em uma árvore AVL
TAVL* insere_no_avl(TAVL *a, int codigo, void *geofig){

	//Verifica se a árvore está vazia
	if(!a) return cria_no_avl(codigo, geofig);

	if(codigo < a->codigo){
		a->esq = insere_no_avl(a->esq, codigo, a->geofig);
		if(altura_avl(a->esq) - altura_avl(a->dir) == 2){
			if(codigo < a->esq->codigo){
				a = rotacao_direita(a);
			} else {
				a = rotacao_esquerda_direita(a);
			}
		}	
	} else if(codigo > a->codigo){
		a->dir = insere_no_avl(a->dir, codigo, a->geofig);
		if(altura_avl(a->dir) - altura_avl(a->esq) == 2){
			if(codigo > a->dir->codigo){
				a = rotacao_esquerda(a);
			} else {
				a = rotacao_direita_esquerda(a);
			}
		}
	}
	a->alt = maior(altura_avl(a->esq), altura_avl(a->dir)) + 1;
	return a;
}	

//Calcula a altura da árvore durante a operação de retirada do nó
int altura_avl_retirada(TAVL *a){
	int altura_esq, altura_dir;
	if(a == NULL) return 0;
	if(a->esq == NULL){
		altura_esq = 0;
	} else {
		altura_esq = 1 + a->esq->alt;
	}
	if(a->dir == NULL){
		altura_dir = 0;
	} else {
		altura_dir = 1 + a->dir->alt;
	}
	if(altura_esq > altura_dir) return (altura_esq);
	return altura_dir;
}

int FB(TAVL *a){
	int altura_esq, altura_dir;
	if(a == NULL) return 0;
	if(a->esq == NULL) {
		altura_esq = 0;
	} else {
		altura_esq = 1 + a->esq->alt;
	}
	if(a->dir == NULL){
		altura_dir = 0;
	} else {
		altura_dir = 1 + a->dir->alt;
	}

	return (altura_esq-altura_dir);
}

//Retira um nó da árvore de acordo com o código informado
TAVL* retira_no_avl(TAVL *a, int x){       
    TAVL *p;
    if(a==NULL){
        return NULL;
    } else{
        if(x > a->codigo){
            a->dir=retira_no_avl(a->dir, x);
            if(FB(a) == 2){
            	if(FB(a->esq) >= 0){
                    a = rotacao_direita(a);
            	}else {
                    a = rotacao_direita_esquerda(a);
                }
            }
        } else {
            if(x < a->codigo){
                    a->esq=retira_no_avl(a->esq, x);
                    if(FB(a) == -2){
                        if(FB(a->dir) <= 0) {
                            a =rotacao_esquerda(a);
                        } else{
                            a = rotacao_direita_esquerda(a);
                        }
                    }    
            } else {
                  if(a->esq != NULL){
                      p = a->esq;
                      while(a->dir != NULL) p=p->dir;
                      a->codigo = p->codigo;
                      a->esq=retira_no_avl(a->esq, p->codigo);
                      if(FB(a)== -2){
                        if(FB(a->dir) <=0){
                            a = rotacao_esquerda(a);
                        } else {
                            a = rotacao_direita_esquerda(a);
                        }
                      }
                   } else{
                      TAVL *x = a;
                      a = a->dir;
                      free(x);
                      return(a);
                  }
            }
        }
    }
    a->alt=altura_avl_retirada(a);
    return(a);
}

//Função auxiliar para imprimir uma árvore AVL
void imprime_nos_avl(TAVL *a, int andar) { 

    if(a){
    	int j;
    	imprime_nos_avl(a->esq, andar+1);
    	for(j=0; j<=andar;j++) printf("   ");
    	printf("%d\n", a->codigo);
    imprime_nos_avl(a->dir, andar+1);
    }
} 
  
//Imprime uma árvore AVL
void imprime_arvore_avl(TAVL *a) { 
   imprime_nos_avl(a, 1); 
}