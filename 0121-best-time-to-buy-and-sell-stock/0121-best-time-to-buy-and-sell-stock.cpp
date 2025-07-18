class Solution {
public:
    int recursion(vector<int>& prices,int minPrice,  int index){
        if(index>=prices.size()){
            return 0;
        }
        int newMinPrice = min(minPrice, prices[index]);
        int profit = prices[index]-minPrice;
        int nextProfit = recursion(prices, newMinPrice, index+1);

        return max(profit, nextProfit);

    }
    int maxProfit(vector<int>& prices) {
        return recursion(prices, prices[0], 0);
    }
};