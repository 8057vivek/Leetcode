class Solution {
public:

    int  recursion(int index, int buy, vector<int>&prices, vector<vector<int>> & dp){
        
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }

        int profit= 0;
        if(buy){
            profit = max((-prices[index]+recursion(index+1, 0, prices, dp)), (0+recursion(index+1 ,1, prices, dp)));
        }
        else{
            profit = max((prices[index]+recursion(index+1, 1, prices, dp)), (recursion(index+1, 0, prices, dp)));
        }

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2,0));
        
        dp[n][0] = dp[n][1] =0;

        for(int index=n-1; index>=0; index--){
            for(int buy=0;buy<=1;buy++){
                int profit= 0;
                if(buy){
                    profit = max(-prices[index]+dp[index+1][0], 0+dp[index+1][1]);
                }
                else{
                    profit = max(prices[index]+dp[index+1][1] , 0+dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }
};