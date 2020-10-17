#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef struct no {
	Item item;
	struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
	Lista n = malloc(sizeof(struct no));
	n->item = x;
	n->prox = p;
	return n;
} 

void exibe(Lista L) {
	while( L != NULL ) {
		printf("%d\n",L->item);
		L = L->prox;
	}
}
Lista inversa(Lista x) {
	Lista t,y = x,r=NULL;
	while(y!=NULL){
		t = y->prox;
		y->prox=r;
		r=y;
		y=t;
	}

	return r;
}


int main(void) {
	int x;
	Lista I = no(3,no(1,no(5,NULL)));
	I=inversa(I);
	exibe(I);
	return 0;
}
