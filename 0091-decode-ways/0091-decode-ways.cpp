class Solution {
public:
    int dp[1001];
    int solve(int index, string& s, int n){
        if(index==n){
            return 1;
        }
        if(s[index]=='0'){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }

        int result = solve(index+1, s, n);
        if(index+1<n){
            if(s[index]=='1' || (s[index]=='2' && s[index+1]<='6')){
            result+=solve(index+2, s,n);
            }
        }
        return dp[index] = result;
    }
    int numDecodings(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));
        
        return solve(0,s,n);
    }
};