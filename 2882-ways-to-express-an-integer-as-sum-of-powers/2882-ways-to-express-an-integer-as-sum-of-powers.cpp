class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    long long power(long long base, int exp) {
        long long result = 1;
        while (exp--) {
            result *= base;
        }
        return result;
    }

    int recursion(int n, int num, int x) {
        if (n == 0) return 1;    
        if (n < 0) return 0;       

        if (dp[n][num] != -1) return dp[n][num];

        long long val = power(num, x);
        if (val > n) return dp[n][num] = 0; 

        int take = recursion(n - val, num + 1, x) % MOD;
        int notTake = recursion(n, num + 1, x) % MOD;

        return dp[n][num] = (take + notTake) % MOD;
    }

    int numberOfWays(int n, int x) {
        dp.assign(n + 1, vector<int>(n + 2, -1));
        return recursion(n, 1, x);
    }
};
