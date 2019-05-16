#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Lnode {
    int data;
    struct Lnode *next;
} Lnode, LinkedList;

int main(void) {
    Lnode *p, *L, *q;
    int value, i;
    L = (LinkedList *) malloc(sizeof(Lnode));
    L->next = NULL;
    while (cin >> value) {
        p = (Lnode *) malloc(sizeof(Lnode));
        p->next = L->next;
        p->data = value;
        L->next = p; //overall recursion of the sequence
    }
    //maxk is the first, mink is the second in nodes
    int maxk = L->next->data;
    p = L->next->next;
    int mink = p->data;
    int out[1000];
    i = 0;
    while (p->next) {//&& p->data >= mink
        q = p->next;
        if (q->data < maxk && q->data > mink) {
            p->next = q->next;
            free(q);
        } else {
            out[i] = q->data;
            i++;
            p = p->next;
        }
    }
    for (int j = i-1; j > 0; --j) {
        cout << out[j] << " ";
    }
    cout << out[0];
    return 0;
}