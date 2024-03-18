/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int arr[], int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target){
            return mid;
        } else if (arr[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*) malloc(2 * sizeof(int));
    int counter = 0;
    int array[numsSize]; 

    for (int i = 0; i < numsSize; i++){
        array[i] = nums[i];
    }

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 1 && nums[0] + nums[i] <= target; i++){
        int left = i;
        int right = numsSize - 1;
        int complement = target - nums[i];
        int searchResult = binarySearch(nums, complement, left, right);

        if (searchResult != -1){
            result[counter++] = i;
            result[counter++] = binarySearch(array, nums[searchResult], 0, numsSize);
            break;
        }       
    }

    *returnSize = counter;
    return result;   
}