class Solution {
public:
    bool recursion(int i, int j, string& s, string & p,vector<vector<int>>& dp){
        if(i>=s.length()){
            if(j>=p.length()){
                return true;
            }
            else{
                for(int k=j;k<p.length();k++){
                    if(p[k]!='*'){
                        return false;
                    }
                }
                return true;
            }
        }
        if(j>=p.length()){
            return false;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] = recursion(i+1,j+1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j] = (recursion(i+1,j,s,p,dp) || recursion(i,j+1,s,p,dp));
        }
        return false;
    }

    bool isMatch(string s, string p) {

        vector<vector<int>> dp(s.length()+1, vector<int>(p.length(),-1));
        return recursion(0,0,s,p,dp);
    }
};