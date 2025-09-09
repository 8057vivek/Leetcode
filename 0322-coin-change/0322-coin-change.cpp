class Solution {
public:
    int recursion(int index, vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }
        if(index<0){
            return 1e9;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }

        int take = 1e9;
        if(coins[index]<=amount){
            take = 1+recursion(index, coins, amount-coins[index],dp);
        }
        int notTake = recursion(index-1, coins, amount,dp);

        return dp[index][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res = recursion(n-1, coins, amount,dp);
        if(res==1e9){
            return -1;
        }
        return res;
    }
};