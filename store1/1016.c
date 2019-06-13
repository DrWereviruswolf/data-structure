#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char va[1000] = {0};
    char vb[1000] = {0};
    int i1 = 0;
    int i2 = 0;
    char item = 'a';
    int secondStr = -1;
    while (scanf("%c", &item)) {
        if (item == ' ') {
            secondStr = 1;
            continue;
        }
        if (!isalpha(item))
            break;
        if (secondStr < 0) {
            va[i1] = item;
            i1++;
        } else {
            vb[i2] = item;
            i2++;
        }
    }
    int resultstr = strcmp(va, vb);
    int result;
    if (resultstr > 0)
        result = 1;
    else if (resultstr == 0)
        result = 0;
    else
        result = -1;
    printf("%d", result);
    return 0;
}