class Solution {
public:
    int recursion(int n,vector<int>& dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int count=0;
        for(int i=1;i<=n;i++){
            count+=recursion(i-1,dp)*recursion(n-i,dp);
        }
        return dp[n] = count;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return recursion(n,dp);
    }
};