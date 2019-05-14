/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
int *twoSum(int *nums, int numsSize, int target) {
    int *sum;
    sum = (int*)malloc(2* sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < numsSize; ++j) {
            if (i != j && nums[i] + nums[j]==target){
                sum[0]=i;
                sum[1]=j;
                return sum;
            }
        }
    }
    return 0;
}