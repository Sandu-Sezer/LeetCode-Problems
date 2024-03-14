int numSubarraysWithSumHelper(int* nums, int numsSize, int goal){
    int left = 0;
    int right = 0;
    int sum = 0;
    int result = 0;
    
    for (left = 0; left < numsSize; left++){
        sum += nums[left];
        while (sum > goal && left >= right){
            sum -= nums[right];
            right++;
        }
        result += left - right + 1;
    }
    return result;
}

int numSubarraysWithSum(int* nums, int numsSize, int goal){
    return numSubarraysWithSumHelper(nums, numsSize, goal) - numSubarraysWithSumHelper(nums, numsSize, goal-1);
}