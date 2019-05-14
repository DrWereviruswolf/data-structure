#include <stdio.h>

#define MAXINT 65535

int answer(int n) {
    int temp = 1;
    for (int i = 1; i < n; ++i) {
        temp *= i;
        if (temp > MAXINT)
            temp = 0;
    }
    for (int j = 1; j < n; ++j) {
        temp *= 2;
        if (temp > MAXINT)
            temp = 0;
    }
    return temp;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n > 7)
        printf("%d", answer(7));
    else
        printf("%d",answer(n));
    return 0;
}