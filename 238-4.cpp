class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsSize = nums.size();

        vector<int> start(numsSize, 1);
        vector<int> finish(numsSize, 1);

        for(int i = 1; i < numsSize; i++){
            start[i] = start[i - 1] * nums[i - 1];
        }

        for(int j = numsSize - 2; j >= 0; j--){
            finish[j] = finish[j + 1] * nums[j + 1];
        }

        vector<int> result(numsSize);

        for(int i = 0; i < numsSize; i++){
            result[i] = start[i] * finish[i];
        }

        return result;
    }
};