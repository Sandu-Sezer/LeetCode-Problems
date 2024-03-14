int numSubarraysWithSumHelper(int* nums, int numsSize, int goal){
    int left = 0;
    int right = 0;
    int sum = 0;
    int result = 0;
    
    for (right = 0; right < numsSize; right++){
        sum += nums[right];
        while (sum > goal && right >= left){
            sum -= nums[left];
            left++;
        }
        result += right - left + 1;
    }
    return result;
}

int numSubarraysWithSum(int* nums, int numsSize, int goal){
    return numSubarraysWithSumHelper(nums, numsSize, goal) - numSubarraysWithSumHelper(nums, numsSize, goal-1);
}