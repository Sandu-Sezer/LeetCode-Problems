/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*) malloc(numsSize * sizeof(int));
    int counter = 0;

    for (int i = 0; i < numsSize; i++){
        for (int j = i + 1; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                result[counter++] = i;
                result[counter++] = j;
            }
        }
    }
    *returnSize = counter;
    return result;
}