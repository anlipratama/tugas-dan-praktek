#include <stdio.h>
#include <stdlib.h>

struct nod {
    struct nod *left;
    char data;
    struct nod *right;
};

typedef struct nod NOD;
typedef NOD POKOK;

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

NOD *NodBaru(char item) {
    NOD *n = (NOD*) malloc(sizeof(NOD));
    if (n != NULL) {
        n->data = item;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void BinaPokok(POKOK **T) {
    *T = NULL;
}

BOOL PokokKosong(POKOK *T) {
    return (BOOL)(T == NULL);
}

void TambahNod(NOD **p, char item) {
    *p = NodBaru(item);
}

void preOrder(POKOK *T) {
    if (!PokokKosong(T)) {
        printf("%c ", T->data);
        preOrder(T->left);
        preOrder(T->right);
    }
}

void inOrder(POKOK *T) {
    if (!PokokKosong(T)) {
        inOrder(T->left);
        printf("%c ", T->data);
        inOrder(T->right);
    }
}

void postOrder(POKOK *T) {
    if (!PokokKosong(T)) {
        postOrder(T->left);
        postOrder(T->right);
        printf("%c ", T->data);
    }
}

int main() {
    POKOK *akar;

    BinaPokok(&akar);

    TambahNod(&akar, 'R');
    TambahNod(&akar->left, 'A');
    TambahNod(&akar->right, 'E');

    TambahNod(&akar->left->left, 'S');
    TambahNod(&akar->left->left->left, 'I');
    TambahNod(&akar->left->left->right, 'T');

    printf("Tampilan secara PreOrder  : ");
    preOrder(akar);

    printf("\nTampilan secara InOrder   : ");
    inOrder(akar);

    printf("\nTampilan secara PostOrder : ");
    postOrder(akar);

    return 0;
}

