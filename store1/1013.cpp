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

int getTop(SqStack *s, elemtype *e) {
    if (s->top == s->base)
        return ERROR;
    *e = *(s->top - 1);
    return OK;
}

int privilege(char item) {
    if (item == '*' || item == '/')
        return 1;
    else if (item == '+' || item == '-')
        return 0;
    else
        return 2;
}

int main() {
    char item = 'a';
    char *compared;
    compared = (char *) malloc(sizeof(char));
    SqStack *S;
    S = (SqStack *) malloc(sizeof(SqStack));
    int state = OK;
    state = initStack(S);
    while (cin >> item && state) {
        if (isalpha(item)) {
            cout << item;
        } else {
            switch (item) {
            case '(':
                state = push(S, item);
                break;
            case ')':
                for (state = pop(S, compared); *compared != '(';) {
                    cout << *compared;
                    state = pop(S, compared);
                }
                break;
            case '*':
            case '/':
            case '+':
            case '-':
                for (state = getTop(S, compared); privilege(*compared)
                                                  >= privilege(item) && state && *compared != '(';) {
                    pop(S, compared);
                    cout << *compared;
                    state = getTop(S, compared);
                }
                state = push(S, item);
                break;
            default:
                break;
            }
        }
    }
    for (; S->base != S->top && state;) {
        state = pop(S, compared);
        cout << *compared;
    }
}