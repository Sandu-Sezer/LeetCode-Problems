double myPow(double x, int n) {
    if (n == 0){
        return 1;
    }

    if (n == INT_MAX){
        return (x == 1) ? 1 : (x == -1) ? -1 : 0;
    }
    if (n == INT_MIN){ 
        return (x == 1 || x == -1) ? 1 : 0;
    }

    if (n < 0 ){

        n = abs(n);
        x = 1 / x;

        if (n % 2 == 0){
            return myPow(x, n / 2) * myPow(x, n / 2);
        } else {
            return x * myPow(x, n / 2) * myPow(x, n / 2);
        }

    } else {

        if (n % 2 == 0){
            return myPow(x, n / 2) * myPow(x, n / 2);
        } else {
            return x * myPow(x, n / 2) * myPow(x, n / 2);
        }

    }
}