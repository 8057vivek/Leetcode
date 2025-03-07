class Solution {
public:
    vector<vector<int>> dp;
    int recursion(vector<int>& prices,int day, int n, bool buy ){ // day means index 
        if(day>=n){
            return 0;
        }

        if (dp[day][buy] != -1) return dp[day][buy];

        int profit=0;

        if(buy){//buy

            int take = recursion(prices, day+1,n, false) - prices[day];
            int notTake = recursion(prices, day+1, n, true);
            profit = max(profit, max(take, notTake));
        }
        else{//sell

            int sell = prices[day] + recursion(prices, day+2, n, true); // cooldown after sell
            int notSell =  recursion(prices, day+1, n, false); // next step we have to sell before buy
            profit = max(profit, max(sell, notSell));
        }
        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));

        bool buy = true;
        return recursion(prices, 0 , n, buy); // true for first day buy
    }
};