class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        long exponent = n;

        if (exponent < 0) {
            exponent = -exponent;
            x = 1 / x;
        }

        while (exponent > 0) {
            if (exponent % 2 == 1)
                result *= x;
            x *= x;
            exponent /= 2;
        }

        return result;
    }
};
