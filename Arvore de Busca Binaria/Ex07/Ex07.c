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
	printf("%d ",A->item);
	exibe_crescente(A->dir);
}


void ins(Item x, Arv *A) {
    if( *A == NULL ) *A = arv(NULL,x,NULL);
    else if( x <= (*A)->item ) ins(x,&(*A)->esq);
    else ins(x,&(*A)->dir);
}

Item remmax(Arv *A) {
    if( *A == NULL ) abort();
    while( (*A)->dir != NULL ) A = &(*A)->dir;
    Arv n = *A;
    Item x = n->item;
    *A = n->esq;
    free(n);
    return x;
} 

void rem_todos(Item x, Arv *A) {
    if( *A == NULL ) return;
    if(x == (*A)->item ) {
        Arv n = *A;
        if( n->esq == NULL ) *A = n->dir;
        else if ( n->dir == NULL ) *A = n->esq;
        else n->item = remmax(&n->esq);
        if( n != *A ){
            free(n);
            rem_todos(x,A);
        } 
    }
    else if( x <= (*A)->item ) rem_todos(x,&(*A)->esq);
    else rem_todos(x,&(*A)->dir);
} 

int main(void) {
    Arv I = NULL;
    Item x;
    while( 1 ) {
        printf("Item? ");
        scanf("%d",&x);
        if( x<0 ) break;
        ins(x,&I);
    }
    printf("\nAntes: ");
    exibe_crescente(I);
    printf("\nItem? ");
    scanf("%d",&x);
    rem_todos(x,&I);
    printf("\nDepois: ");
    exibe_crescente(I);
    return 0;
}
