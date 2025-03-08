class Solution {
public:
    int solve(vector<int>& coins, int amount, int index, int n, vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }

        if(index>=n){
            return INT_MAX-1;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        
        int  take= INT_MAX-1;
        if(coins[index]<=amount){
            take = 1+solve(coins, amount-coins[index], index, n, dp);
        }
        int notTake = solve(coins, amount, index+1, n,dp);

        return dp[index][amount]=min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int result = solve(coins, amount, 0, n,dp);
        if(result==INT_MAX-1){
            return -1;
        }
        return result;
    }
};