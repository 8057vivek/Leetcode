class Solution {
public:
    int recursion(vector<int>& prices,int minPrice,  int index,vector<int>& dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }

        int newMinPrice = min(minPrice, prices[index]);
        int profit = prices[index]-minPrice;
        int nextProfit = recursion(prices, newMinPrice, index+1,dp);

        return dp[index]= max(profit, nextProfit);

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp (n,-1);
        return recursion(prices, prices[0], 0,dp);
    }
};