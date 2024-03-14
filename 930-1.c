int numSubarraysWithSum(int* nums, int numsSize, int goal){
    int k = 0;
    int result = 0;

    while (k <= numsSize - goal){
        int sum = 0;

        for (int i = k; i < numsSize; i++){
            sum += nums[i];

            if (sum == goal){
                result++;
            }

            if (sum > goal){
                break;
            }
        }
        k++;
    }
    return result;
}