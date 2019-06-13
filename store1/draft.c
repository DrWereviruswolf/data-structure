/* pattern maching
 * kmp algorithm
 */
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAXSTRLEN 100
typedef char string;

void getNext(string *pattern, int next[MAXSTRLEN]) {
    int j, k;
    j = 0;
    k = -1;
    for (int i = 0; i < MAXSTRLEN; ++i) {
        next[i] = 0;
    }
    next[0] = -1;
    while (j < strlen(pattern)) {
        if (k == -1 || pattern[j] == pattern[k]) {
            j++;
            k++;
            next[j] = k;
        }//失配
        else k = next[k];
    }
}

int strIndexKMP(string *s, string *t, int pos) {
    int next[MAXSTRLEN];
    getNext(t, next);
    int i, j;
    i = pos - 1;
    j = 0;
    while (i < strlen(s) && j < strlen(t))
        if (j == -1 || s[i] == t[j]) {
            i++;
            j++;
        } else j = next[j];
    if (j>= strlen(t))
        return i-strlen(t)+1;
    else
        return 0;
}

int main() {
    char va[MAXSTRLEN], vb[MAXSTRLEN];
    scanf("%s", va);
    scanf("%s", vb);
    printf("%d",strIndexKMP(va,vb,0));
}