class Solution {
public:
    int recursion(int index,int buy, int cap,  vector<int>& prices, vector<vector<vector<int>>> & dp){
        if(cap==0){
            return 0;
        }
        if(index==prices.size()){
            return 0;
        }

        if(dp[index][buy][cap]!=-1){
            return dp[index][buy][cap];
        }


        int profit = 0;
        if(buy){
            profit =  max((-prices[index]+recursion(index+1, 0, cap,prices,dp)), 0+recursion(index+1, 1, cap,prices,dp));
        }else{
            profit =  max((prices[index]+recursion(index+1, 1, cap-1,prices,dp)), 0+recursion(index+1, 0, cap,prices,dp));
        }
        return dp[index][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3, 0)));

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int cap = 1;cap<=2;cap++){
                    if(buy){
                        dp[index][buy][cap] =  max(-prices[index]+dp[index+1][0][cap], 0+dp[index+1][1][cap]);
                    }else{
                        dp[index][buy][cap] =  max(prices[index]+dp[index+1][1][cap-1], 0+dp[index+1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};