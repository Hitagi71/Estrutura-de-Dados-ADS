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

void ins(Item x, Lista *L){
	while( *L != NULL && (*L)->item < x ){
		L = &(*L)->prox;
	}
	*L = no(x,*L);
}


void exibe_decrescente(Lista L) {
	if(L!=NULL){
		exibe_decrescente(L->prox);
		printf("%d\n",L->item);
	}
}

int main(void){
	Lista I=NULL;
	ins(4,&I);
	ins(1,&I);
	ins(6,&I);
	ins(5,&I);
	ins(2,&I);
	exibe_decrescente(I);
	return 0;
}
