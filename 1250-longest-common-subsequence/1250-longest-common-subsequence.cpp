class Solution {
public:
    int tabulation(string text1, string text2){
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> table(m+1,vector<int>(n+1,0));
        
        for(int i=m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    table[i][j] = 1+table[i+1][j+1];
                }
                else{
                    table[i][j] = max(table[i+1][j], table[i][j+1]);
                }
            }
        }
        return table[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return tabulation(text1,text2);
    }
};