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

void exibe_crescente(Arv A) {
	if( A==NULL ) return;
	exibe_crescente(A->esq);
	printf("%d",A->item);
	exibe_crescente(A->dir);
}

void ins(Item x, Arv *A) {
    if( *A == NULL ) *A = arv(NULL,x,NULL);
    else if( x <= (*A)->item ) ins(x,&(*A)->esq);
    else ins(x,&(*A)->dir);
} 


int main(void) {
    Arv I = NULL;
    ins(7,&I);
    ins(4,&I);
    ins(6,&I);
    ins(8,&I);
    ins(2,&I);
    ins(5,&I);
    ins(3,&I);
    ins(1,&I);
    exibe_crescente(I);
    return 0;
}
