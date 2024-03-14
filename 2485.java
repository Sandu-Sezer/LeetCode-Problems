class Solution {
    public int pivotInteger(int n) {
        if (n == 1){
        return n;
        }

        int sum = 0;
        for (int i = 1; i <= n; i++){
            sum += i;
        }

        int left = 0;
        int right = sum;
        int k = 1;

        while (left <= right){
            left += k;
            right -= k;
            k++;

            if ((left + k) == right){
                return k;
            }
   
        }
    return -1;
    }
}