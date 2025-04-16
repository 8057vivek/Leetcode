class Solution {
public:
    int recursion(int i, int j, string s1, string s2, vector<vector<int>> & dp){
        if(i>=s1.length() || j>s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j] = recursion(i+1, j+1, s1, s2, dp)+1;
        }else{
            return dp[i][j] =  max(recursion(i+1, j, s1, s2, dp), recursion(i, j+1, s1, s2, dp));
        }
    }
    int minDistance(string word1, string word2) {

        int l1 = word1.length();
        int l2 = word2.length();

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
        int lcs = recursion(0, 0, word1, word2, dp);
        
        return (l1+l2)-(2*lcs);
    }
};