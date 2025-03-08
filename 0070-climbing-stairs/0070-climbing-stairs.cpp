class Solution {
public:
    int dp[46];
    int climbStairs1(int n) {
        if(n==0){
            return 1;
        }
        if(n < 0) return 0;  
        if(dp[n]!=-1){
            return dp[n];
        }

        int oneStep = climbStairs1(n-1);
        int twoStep = climbStairs1(n-2);

        return dp[n] = oneStep+twoStep;
    }
    int climbStairs(int n){
        memset(dp, -1, sizeof(dp));
        return climbStairs1(n);
    }
};