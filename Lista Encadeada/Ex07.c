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

void ultimo(Lista L){
	while( L != NULL ) {
		L = L->prox;
		if(L->prox == NULL){
			printf("Ultimo = %d\n",L->item);
			break;
		}
	}
}
int main(void) {
	Lista I = no(3,no(1,no(5,NULL)));
	ultimo(I);
	return 0;
}
