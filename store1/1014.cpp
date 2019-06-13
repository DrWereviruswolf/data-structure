#include <iostream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

#define INITSIZE 100
#define INCREMENTSIZE 10
#define OK 1
#define ERROR 0

typedef char elemtype;
typedef struct {
    elemtype *top;
    elemtype *base;
    int stacksize;
} SqStack;

int initStack(SqStack *s) {
    s->base = (elemtype *) malloc(INITSIZE * sizeof(elemtype));
    if (!s->base)
        return ERROR;
    s->top = s->base;
    s->stacksize = INITSIZE;
    return OK;
}

int pop(SqStack *s, elemtype *e) {
    if (s->top == s->base)
        return ERROR;
    *e = *--s->top;
    return OK;
}

int push(SqStack *s, elemtype e) {
    if (s->top - s->base >= s->stacksize) {
        s->stacksize += INCREMENTSIZE;
        s->base = (elemtype *) realloc(s->base, (s->stacksize) * sizeof(elemtype));
        if (!s->base)
            return ERROR;
    }
    *s->top++ = e;
    return OK;
}

int main() {
    elemtype item = 'a';
    elemtype *compared;
    compared = (elemtype *) malloc(sizeof(elemtype));
    elemtype array[INITSIZE] = "0";
    SqStack *S;
    S = (SqStack *) malloc(sizeof(SqStack));
    int state = OK;
    int i = 0;
    state = initStack(S);
    while (cin >> item && state) {
        if (item == '@')
            break;
        array[i++] = item;
        state = push(S,item);
    }
    for (int j = 0; array[j] ; ++j) {
        state = pop(S,compared);
        if (array[j]!= *compared || !state){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}