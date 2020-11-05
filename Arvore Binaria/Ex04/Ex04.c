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


int folhas(Arv A){
    if(A->dir == NULL && A->esq == NULL){
        return 1;
    }

	int esq = 0;
	int dir = 0;

	if(A->esq != NULL){
		esq = folhas(A->esq);
	}

	if(A->dir != NULL){
		dir = folhas(A->dir);
	}
    return esq + dir;
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

	printf("Folhas = %d",folhas(I));
	return 0;
}
