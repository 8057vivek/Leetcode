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
        vector<vector<int>> next(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    if(buy){
                        curr[buy][cap] = max(-prices[index] + next[0][cap],next[1][cap]);
                    } else {
                        curr[buy][cap] = max(prices[index] + next[1][cap-1],next[0][cap]);
                    }
                }
            }
            next = curr;
        }

        return next[1][2];

    }
};