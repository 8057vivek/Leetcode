class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<bool> isPrime(n+1, true);
    
        isPrime[0]=isPrime[1] = false;
        int count = n-2;

        for (int p = 2; p * p < n; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i < n; i += p) {
                    if (isPrime[i]) {
                        isPrime[i] = false;
                        count--;
                    }
                }
            }
        }
        return count;
    }
};