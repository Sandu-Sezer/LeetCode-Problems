/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    typedef struct iv{
        int value;
        int index;
    } ValueIndex;

    ValueIndex* ValuesAndIndexes = (ValueIndex*) malloc(numsSize * sizeof(ValueIndex));
    int* result = (int*) malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++){
        ValuesAndIndexes[i].value = nums[i];
        ValuesAndIndexes[i].index = i;
    }

    qsort(ValuesAndIndexes, numsSize, sizeof(ValueIndex), compare);

    int left = 0;
    int right = numsSize - 1;
    int counter = 0;

    while (left <= right){
        int sum = ValuesAndIndexes[left].value + ValuesAndIndexes[right].value;
        
        if (sum == target){
            result[counter++] = ValuesAndIndexes[left].index;
            result[counter++] = ValuesAndIndexes[right].index;
            break;
        } else if (sum < target){
            left++;
        } else {
            right--;
        }
    }

    *returnSize = counter;
    free(ValuesAndIndexes);
    return result;   
}