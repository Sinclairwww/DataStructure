#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int exhaustion(int*, int);
int exhaustion_improve(int*, int);
int dp(int*, int);
int* getNums(char*, int*);
double TimeOfExhaustion(int*, int, int*);
double TimeOfExhaustion_improve(int*, int, int*);
double TimeOfDp(int*, int, int*);
int main() {
    int res1 = 0, res2 = 0, res3 = 0;
    double time1 = 0.0, time2 = 0.0, time3 = 0.0;
    char filename[20] = "\0";
    int* nums, returnSize;
    gets(filename);
    nums = getNums(filename, &returnSize);
    time1 = TimeOfExhaustion(nums, returnSize, &res1);
    time2 = TimeOfExhaustion_improve(nums, returnSize, &res2);
    time3 = TimeOfDp(nums, returnSize, &res3);
    printf("算法一的结果:%d ,所用时间:%.9lfs\n", res1, time1);
    printf("算法二的结果:%d ,所用时间:%.9lfs\n", res2, time2);
    printf("算法三的结果:%d ,所用时间:%.9lfs\n", res3, time3);
    free(nums);
    return 0;
}
int* getNums(char* filename, int* returnSize) {
    FILE* fp = fopen(filename, "r");
    int* nums, i = 0;
    char tmp1[10] = "\0", tmp2[10] = "\0";
    sscanf(filename, "%[a-z]%d%s",tmp1, &(*returnSize),tmp2);
    nums = (int*)malloc(sizeof(int) * (*returnSize));
    while (fscanf(fp, "%d", &nums[i]) != EOF)
        i++;
    fclose(fp);
    return nums;
}
int exhaustion(int* nums, int numsSize) {
    int thisSum = 0, maxSum = -2147483647, i, j, k;
    for (i = 0; i < numsSize; i++) {
        for (j = i; j < numsSize; j++) {
            thisSum = 0;
            for (k = i; k <= j; k++)
                thisSum += nums[k];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}
int exhaustion_improve(int* nums, int numsSize) {
    int thisSum = 0, maxSum = -2147483647, i, j;
    for (i = 0; i < numsSize; i++) {
        thisSum = 0;
        for (j = i; j < numsSize; j++) {
            thisSum += nums[j];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}
int dp(int* nums, int numsSize) {
    int thisSum = 0, maxSum = -2147483647, i;
    for (i = 0; i < numsSize; i++) {
        thisSum += nums[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum <= 0)
            thisSum = 0;
    }
    return maxSum;
}
double TimeOfExhaustion(int* nums, int numsSize, int* res) {
    int tmp = 0, i;
    clock_t start, end;
    double duration = 0.0;
    start = clock();
    for (i = 0; i < 100; i++)
        tmp = exhaustion(nums, numsSize);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    *res = tmp;
    return duration / 100;
}
double TimeOfExhaustion_improve(int* nums, int numsSize, int* res) {
    int tmp = 0, i;
    clock_t start, end;
    double duration = 0.0;
    start = clock();
    for (i = 0; i < 1000; i++)
        tmp = exhaustion_improve(nums, numsSize);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    *res = tmp;
    return duration / 1000;
}
double TimeOfDp(int* nums, int numsSize, int* res) {
    int tmp = 0, i;
    clock_t start, end;
    double duration = 0.0;
    start = clock();
    for (i = 0; i < 10000; i++)
        tmp = dp(nums, numsSize);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    *res = tmp;
    return duration / 10000;
}
