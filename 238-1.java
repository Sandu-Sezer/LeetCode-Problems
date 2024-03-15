class Solution {
    public int[] productExceptSelf(int[] nums) {
        int counter = 0;
        int[] result = new int[nums.length];

        while (counter < nums.length){
            int p = 1;
            int left = 0;
            int right = nums.length - 1;

            while (left != counter){
                p *= nums[left];
                left++;
            }
            while (right != counter){
                p *= nums[right];
                right--;
            }
            result[counter] = p;
            counter++;
        }
        return result;
    }
}