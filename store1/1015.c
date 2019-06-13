#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void *compress(char *string, char *stringCompress) {
    char *pString = string;
    char *pStrComprs;
    for (; *pString != 0; ++pString) {
        for (pStrComprs = stringCompress;
             *pStrComprs != 0; ++pStrComprs) {
            if (*pStrComprs == *pString)
                break;
        }
        if (*pStrComprs == 0)
            *pStrComprs = *pString;
    }
}

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
        if (secondStr < 0) {
            va[i1] = item;
            i1++;
        } else {
            vb[i2] = item;
            i2++;
        }
        if(!isalpha(item))
            break;
    }
    int i, j;
    char vaComprs[500] = {0};
    char vbComprs[500] = {0};
    i = j = 0;
    compress(va, vaComprs);
    compress(vb, vbComprs);
    char outchar[500] = {0};
    int outAddr[500] = {0};

    for (; vaComprs[i] != 0; ++i) {
        if (strchr(vbComprs, vaComprs[i]) == NULL) {
            outchar[j] = vaComprs[i];
            outAddr[j++] = strchr(va, vaComprs[i]) - va;
        }
    }

    if (j == 0)
        printf("-1");
    else{
        printf("%s ",outchar);
        for (int k = 0; k < j; ++k) {
            printf("%d", outAddr[k]);
        }
    }
    return 0;
}