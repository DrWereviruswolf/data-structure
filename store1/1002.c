#include <stdio.h>
//bubble sort 3 elem

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main() {
    int a[3];
    for (int i = 0; i < 3; ++i) {
        scanf("%d", a+i);
    }
    if (a[0] < a[1])
        swap(a, a + 1);
    if (a[1] < a[2])
        swap(a + 1, a + 2);
    if (a[0] < a[1])
        swap(a, a + 1);
    for (int j = 0; j < 2; ++j) {
        printf("%d ", a[j]);
    }
    printf("%d",a[2]);
    return 0;
}