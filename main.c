#include <stdio.h>

void test(int *sum) {

    int x;
    scanf("%d",&x);
    if (x == 0)
        *sum = 0;
    else {
        test(*sum);
        *sum += x;
    }
    printf("%d",sum);
}

int main() {
    int *s;
    *s = 1;
    test(s);
    return 0;
}