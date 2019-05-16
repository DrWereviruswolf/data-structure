#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Lnode {
    char data;
    struct Lnode *next;
} Lnode, LinkedList;

int main(void) {
    Lnode *p, *L;
    char value;
    L = (LinkedList *) malloc(sizeof(Lnode));
    L->next = NULL;
    while (cin >> value) {
        if (value!=','){
            p = (Lnode *) malloc(sizeof(Lnode));
            p->next = L->next;
            p->data = value;
            L->next = p;
        }
    }

    p = L->next;

    while (p->next) {
        cout << p->data << ",";
        p = p->next;
    }
    cout << p->data;
    return 0;
}