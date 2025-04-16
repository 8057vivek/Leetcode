class Solution {
public:
    int maxSide = 0;
    int recursion(vector<vector<char>>& matrix, int r, int c,vector<vector<int>>& dp){
        if(r>=matrix.size() || c>=matrix[0].size()){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int right = recursion(matrix, r, c+1, dp);
        int bottom = recursion(matrix, r+1, c, dp);
        int diagonal = recursion(matrix, r+1, c+1, dp);

        if(matrix[r][c]=='1'){
            int side = min(right, min(bottom, diagonal))+1;
            maxSide = max(maxSide, side);
            return dp[r][c] = side;
        }else{
            return dp[r][c] =  0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        recursion(matrix,0,0, dp);
        return maxSide*maxSide;
    }
};