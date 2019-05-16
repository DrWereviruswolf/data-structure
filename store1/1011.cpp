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
    int signpost = -1;
    int *compared;
    compared = (int *)malloc(sizeof(int));
    SqStack *S;
    S = (SqStack*)malloc(sizeof(SqStack));
    int state = OK;
    state = initStack(S);
    while (cin >> item && state) {
        if (item == '&') {
            signpost++;
        } else if (item == '@') {
            if (S->top == S->base) {
                cout << 1;
                return 0;
            }
        } else {
            if (signpost < 0) {
                state = push(S, item);
            } else {
                state = pop(S, compared);
                if (*compared != item) {
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}