#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef struct arv {
	struct arv *esq;
	Item item;
	struct arv *dir;
} *Arv;

Arv arv(Arv e, Item x, Arv d) {
	Arv n = malloc(sizeof(struct arv));
	n->esq = e;
	n->item = x;
	n->dir = d;
	return n;
} 

void exibe(Arv A,int n) {
	if( A==NULL ) return;
	exibe(A->dir,n+1);
	printf("%*s%d\n",3*n,"",A->item);
	exibe(A->esq,n+1);
}


Arv clone(Arv A){
    if(A == NULL){
        return A;
    }

    Arv dir = clone(A->dir);
    Arv esq = clone(A->esq);

    return arv(esq,A->item,dir);
}

int main(void) {
	Arv I = arv(arv(NULL,
				2,
				NULL),
			1,
			arv(NULL,
				3,
				arv(NULL,
					4,
					NULL)));

    Arv A = clone(I);
    exibe(A,0);
	return 0;
}
