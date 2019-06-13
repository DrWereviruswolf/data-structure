
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAXSTRLEN 100

void getNext(char *pattern, int *next) {
    int j, k;
    j = 0;
    k = -1;
//    printf("%ld\n",strlen(pattern));
    for (int i = 0; i < strlen(pattern); ++i) {
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
    j--;
}

int main() {
    char va[MAXSTRLEN] = {0};
    scanf("%s", va);
    int next[strlen(va)];
    getNext(va, next);
}