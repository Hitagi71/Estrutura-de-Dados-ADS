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
int pertence(int x,Lista L) {
	while( L != NULL ) {
		if(L->item==x){
			return 1;
		}
		L = L->prox;
	}
	return 0;
}

int main(void) {
	int x;
	Lista I = no(3,no(1,no(5,NULL)));
	printf("Escolha um numero: ");
	scanf("%d",&x);
	if(pertence(x,I)){
		printf("%d esta contido na lista\n",x);
	}else{
		printf("%d nao esta contido na lista\n",x);
	}
	return 0;
}
