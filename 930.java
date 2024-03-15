class Solution {
    public int numSubarraysWithSumHelper(int[] nums, int goal) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int result = 0;
    
        for (right = 0; right < nums.length; right++){
            sum += nums[right];
            while (sum > goal && right >= left){
                sum -= nums[left];
                left++;
            }
            result += right - left + 1;
        }
        return result;
    }

    public int numSubarraysWithSum(int nums[], int goal){
        return numSubarraysWithSumHelper(nums, goal) - numSubarraysWithSumHelper(nums, goal-1);
    }
}