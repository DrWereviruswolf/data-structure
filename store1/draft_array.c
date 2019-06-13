#include <stdlib.h>

#define ERROR 0
#define DIM 2

typedef int elemType;
typedef struct {
    elemType *base;
    int *bounds;        //维界基址,allocated by initarray
    int *constants;     //映像函数常量基址
} array;
typedef int status;

status initArray(array *A) {
    A->bounds = (int *) malloc(DIM * sizeof(int));
    if (!A->bounds)
        return ERROR;
    int elemTotal = 1;
}