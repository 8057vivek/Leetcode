class Solution {
public:
    int recursion(vector<int>& days, vector<int>& costs, int index, int n, vector<int>& dp){
        
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int oneday = costs[0] + recursion(days, costs, index+1,n,dp);

        int j;
        for(j=index;j<n && days[j]<days[index]+7;j++);

        int SevenDay = costs[1] + recursion(days, costs, j,n,dp);

        for(j=index;j<n && days[j]<days[index]+30;j++);
        int ThirtyDay = costs[2] + recursion(days, costs, j,n, dp);

        dp[index] = min(oneday, min(SevenDay, ThirtyDay));
        return dp[index];


    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        
        return recursion(days, costs, 0, n,dp);
    }
};