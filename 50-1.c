double myPow(double x, int n) {
    double result = 1.0;

    if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
    if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
    

    if (n == 0){
        return result;
    } else if (n > 0){
        for (int i = 1; i <= n; i++){
            result *= x;
            }
    } else {
        for (int i = -1; i >= n; i--){
            result /= x;
        }
    }

    return result;
}