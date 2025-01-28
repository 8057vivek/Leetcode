class Solution {
public:
    int recursiveFunction(int i, int j, string& s1, string& s2,vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 0;
        if(s1[i]==s2[j]){
            ans = 1+ recursiveFunction(i-1,j-1,s1,s2,dp);
        }else{
            ans = max(recursiveFunction(i-1,j,s1,s2,dp),recursiveFunction(i,j-1,s1,s2,dp));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return recursiveFunction(n - 1, m - 1, text1, text2, dp);
    }
};