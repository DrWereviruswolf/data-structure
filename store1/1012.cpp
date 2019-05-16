#include <iostream>
#include <stdlib.h>

using namespace std;

#define INITSIZE 100
#define INCREMENTSIZE 10
#define OK 1
#define ERROR 0

typedef struct {
    int *top;
    int *base;
    int stacksize;
} SqStack;

int initStack(SqStack *s) {
    s->base = (int *) malloc(INITSIZE * sizeof(int));
    if (!s->base)
        return ERROR;
    s->top = s->base;
    s->stacksize = INITSIZE;
    return OK;
}

int pop(SqStack *s, int *e) {
    if (s->top == s->base)
        return ERROR;
    *e = *--s->top;
    return OK;
}

int push(SqStack *s, int e) {
    if (s->top - s->base >= s->stacksize) {
        s->stacksize += INCREMENTSIZE;
        s->base = (int *) realloc(s->base, (s->stacksize) * sizeof(int));
        if (!s->base)
            return ERROR;
    }
    *s->top++ = e;
    return OK;
}

int main() {
    char item = 'a';
    int *compared;
    compared = (int *)malloc(sizeof(int));
    SqStack *S;
    S = (SqStack*)malloc(sizeof(SqStack));
    int state = OK;
    state = initStack(S);
    while (cin >> item && state) {
        if (item == '('){
            state = push(S,item);
            if (!state) break;
        }else if (item == ')'){
            state = pop(S,compared);
            if (!state) break;
        }else
            continue;
    }
    if (S->top != S->base)
        state = 0;
    cout << state;
}