class Solution {
public:
    int Ways(int i, int j,string& s, string& t,vector<vector<int>>& dp){
        if (j == t.length()) return 1; 
        if (i == s.length()) return 0; 

        if (dp[i][j] != -1) return dp[i][j];  

        int ans = 0;
        if (s[i] == t[j]) {
            ans += Ways(i+1,j+1,s,t,dp); 
        }
        ans+=Ways(i+1,j,s,t,dp);

        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,-1));
        return Ways(0,0,s,t,dp);
    }
};