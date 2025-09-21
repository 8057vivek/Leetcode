class Solution {
public:
    int recursion(int index,int buy, int cap,  vector<int>& prices){
        if(cap==0){
            return 0;
        }
        if(index==prices.size()){
            return 0;
        }

        if(buy){
            return max((-prices[index]+recursion(index+1, 0, cap,prices)), 0+recursion(index+1, 1, cap,prices));
        }
        return max((prices[index]+recursion(index+1, 1, cap-1,prices)), 0+recursion(index+1, 0, cap,prices));
    }
    int maxProfit(vector<int>& prices) {
        return recursion(0,1,2,prices);
    }
};