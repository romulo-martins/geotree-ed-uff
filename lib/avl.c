/*
 +=====================================+
 | Arvore AVL (AVL Tree - AT) |
 +=====================================+
*/

#include "avl.h"
#include "figuras.h"

AVL* new_avl(void){
	return NULL;
}

//Busca um elemento na árvore de acordo com um código informado
AVL* avl_find(AVL *a, int codigo){
	if(a == NULL) return NULL;
	if(codigo < a->cod) return avl_find(a->esq, codigo);
	if(codigo > a->cod) return avl_find(a->dir,codigo);
	return a;
}

//Função que retorna a maior altura
int biggest(int altura_esq, int altura_dir){
	return (altura_esq > altura_dir) ? altura_esq : altura_dir;
}

// Calcula a altura da árvore AVL
int height_avl(AVL *a){
	if(a == NULL) return -1;
	return a->alt;
}


//Performa rotação à direita.
AVL* right_rot(AVL *t){
	AVL *p = NULL;
	p = t->esq;
	t->esq = p->dir;
	p->dir = t;
	t->alt = biggest(height_avl(t->esq), height_avl(t->dir)) + 1;
	p->alt = biggest(height_avl(p->esq), t->alt) + 1;
	return p;
}

//Performa rotação à esquerda.
AVL* left_rot(AVL *p){
	AVL *t;
	t = p->dir;
	p->dir = t->esq;
	t->esq = p;
	p->alt = biggest(height_avl(p->esq), height_avl(p->dir)) + 1;
	t->alt = biggest(height_avl(t->dir), p->alt) + 1;
	return t;
}

//Performa rotação dupla esquerda-direita (RED)
AVL* left_right_rot(AVL* q){
	q->esq = left_rot(q->esq);
	return right_rot(q);
}

AVL* right_left_rot(AVL * p){
	p->dir = right_rot(p->dir);
	return left_rot(p);
}

//Cria um nó para a árvore AVL
AVL* create_node_avl(int codigo, TFIGURA* geofig){
	AVL *node = (AVL*) malloc(sizeof(AVL));
	node->cod = codigo;
	node->geofig = copia_figura(geofig);
	node->esq = NULL;
	node->dir = NULL;
	return node;
}

//Função recursiva para adicionar um nó em uma árvore AVL
AVL* insert_avl(AVL *a, int codigo, TFIGURA *geofig){

	//Verifica se a árvore está vazia
	if(!a) a = create_node_avl(codigo, geofig);

	if(codigo < a->cod){
		a->esq = insert_avl(a->esq, codigo, a->geofig);
		if(height_avl(a->esq) - height_avl(a->dir) == 2){
			if(codigo < a->esq->cod){
				a = right_rot(a);
			} else {
				a = left_right_rot(a);
			}
		}	
	} else if(codigo > a->cod){
		a->dir = insert_avl(a->dir, codigo, a->geofig);
		if(height_avl(a->dir) - height_avl(a->esq) == 2){
			if(codigo > a->dir->cod){
				a = left_rot(a);
			} else {
				a = right_left_rot(a);
			}
		}
	}
	a->alt = biggest(height_avl(a->esq), height_avl(a->dir)) + 1;
	return a;
}	

//Calcula a altura da árvore durante a operação de retirada do nó
int remove_height_avl(AVL *a){
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

int FB(AVL *a){
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
AVL* remove_avl(AVL *a, int x){       
    AVL *p;
    if(a==NULL){
        return NULL;
    } else{
        if(x > a->cod){
            a->dir=remove_avl(a->dir, x);
            if(FB(a) == 2){
            	if(FB(a->esq) >= 0){
                    a = right_rot(a);
            	}else {
                    a = right_left_rot(a);
                }
            }
        } else {
            if(x < a->cod){
                    a->esq=remove_avl(a->esq, x);
                    if(FB(a) == -2){
                        if(FB(a->dir) <= 0) {
                            a =left_rot(a);
                        } else{
                            a = right_left_rot(a);
                        }
                    }    
            } else {
                  if(a->esq != NULL){
                      p = a->esq;
                      while(a->dir != NULL) p=p->dir;
                      a->cod = p->cod;
                      a->esq=remove_avl(a->esq, p->cod);
                      if(FB(a)== -2){
                        if(FB(a->dir) <=0){
                            a = left_rot(a);
                        } else {
                            a = right_left_rot(a);
                        }
                      }
                   } else{
                      AVL *x = a;
                      a = a->dir;
                      free(x);
                      return(a);
                  }
            }
        }
    }
    a->alt=remove_height_avl(a);
    return(a);
}

//Libera espaço de memória da árvore
void free_avl(AVL *a){
	if(a){
		free_avl(a->esq);
		free_avl(a->dir);
		free(a->geofig);
		free(a);
	}
}

//Função auxiliar para imprimir uma árvore AVL
void print_aux_avl(AVL *a, int andar, int imprimir_figura) { 

    if(a){
    	int j;
    	print_aux_avl(a->esq, andar+1, imprimir_figura);
    	for(j=0; j<=andar;j++) printf("   ");
    	printf("%d ", a->cod);
    	if(imprimir_figura && a->geofig) print_figura(a->geofig); else printf("\n");
    	print_aux_avl(a->dir, andar+1, imprimir_figura);
    }
} 
  
//Imprime uma árvore AVL
void avl_print(AVL *a) { 
   print_aux_avl(a, 1, 0); 
}

// Converte uma árvore genérica em uma árvore AVL
AVL* convert_2_avl(GenTree *gentree, AVL *avl){
	if(gentree){
		avl = insert_avl(avl, gentree->cod, gentree->geofig);
		avl = convert_2_avl(gentree->child, avl);
		avl = convert_2_avl(gentree->brother, avl);
	}
	return avl;
}

void print_avl_figure(int cod, AVL *at) {
    AVL *a = avl_find(at, cod);
    if (a->geofig)
        print_figura(a->geofig);
    else
        printf("Este nó não possui figura associada.\n");
}