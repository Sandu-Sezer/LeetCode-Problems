int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* sortedSquares = (int*) malloc(numsSize * sizeof(int));

    int left = 0;
    int right = numsSize - 1;
    int result = numsSize - 1;

    while (left <= right){
        int leftSquared = nums[left] * nums[left];
        int rightSquared = nums[right] * nums[right];

        if (leftSquared > rightSquared){
            sortedSquares[result] = leftSquared;
            left++;
        } else {
            sortedSquares[result] = rightSquared;
            right--;
        }

        result--;
    }

    *returnSize = numsSize;

    return sortedSquares;
}