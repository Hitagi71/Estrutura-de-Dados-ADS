#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no{
	Item item;
	struct no *prox;
} *Lista;

Lista no(Item x,Lista p){
	Lista n = malloc(sizeof(struct no));
	n->item = x;
	n->prox = p;
	return n;
} 

int ins_sr(Item x, Lista *L) {
    while( *L != NULL ) {
       	if(x == (*L)->item){
			return 0;
		}
		L = &(*L)->prox;
    }

	return 1;
}

void ins(Item x, Lista *L){
	if(*L != NULL && (*L)->item < x ){
		ins(x,&(*L)->prox);
	}else{
		*L = no(x,*L);
	}
}


void exibe(Lista L) {
    while( L != NULL ) {
        printf("%d\n",L->item);
        L = L->prox;
    }
}

int main(void){
	Lista I=NULL;
	ins(4,&I);
	ins(6,&I);
	ins(3,&I);
	ins(5,&I);
	ins(2,&I);
	exibe(I);
	return 0;
}
