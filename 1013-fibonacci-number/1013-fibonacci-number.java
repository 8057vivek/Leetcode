class Solution {
    public int print(int n,int []dp){
    if(n<=1){
        return n;
    }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=print(n-1,dp)+print(n-2,dp);
    }
    public int fib(int n) {
        int dp[]=new int[n+1];
        Arrays.fill(dp,-1);
        return print(n,dp);
    }
}