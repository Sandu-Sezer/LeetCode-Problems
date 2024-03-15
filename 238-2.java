class Solution {
    public int[] productExceptSelf(int[] nums) {
        int counter = 0;
        int[] result = new int[nums.length];

        while (counter < nums.length){
            int pleft = 1;
            int pright = 1;

            for(int i = 0; i != counter; i++){
                pleft *= nums[i];
            }

            for(int j = nums.length - 1; j != counter; j--){
                pright *= nums[j];
            }

            result[counter] = pleft * pright;
            counter++;
        }
        return result;
    }
}