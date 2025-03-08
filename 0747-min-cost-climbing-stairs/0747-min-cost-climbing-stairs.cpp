class Solution {
public:
    int dp[1001];
    int recursion(vector<int>& cost, int index, int n){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int oneStep = cost[index] +  recursion(cost, index+1,n);
        int TwoStep = cost[index] + recursion(cost, index+2,n);

        return dp[index]=min(oneStep, TwoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        int n = cost.size();
        return min(recursion(cost, 0,n), recursion(cost, 1,n));
    }
};