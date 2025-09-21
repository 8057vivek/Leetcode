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

        vector<int> ahead(2,0), curr(2, 0);
        
        ahead[0] = ahead[1] =0;

        for(int index=n-1; index>=0; index--){
            for(int buy=0;buy<=1;buy++){
                int profit= 0;
                if(buy){
                    profit = max(-prices[index]+ahead[0], ahead[1]);
                }
                else{
                    profit = max(prices[index]+ahead[1] , ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }

        return ahead[1];
    }
};