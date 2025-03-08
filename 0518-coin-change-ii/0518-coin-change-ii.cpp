class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;  // Base case

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                long long temp = (long long)dp[i] + dp[i - coin]; // Use long long for safe addition
                if (temp > INT_MAX) temp = INT_MAX;  // Prevent overflow
                dp[i] = (int)temp;
            }
        }
        return dp[amount];
    }
};
