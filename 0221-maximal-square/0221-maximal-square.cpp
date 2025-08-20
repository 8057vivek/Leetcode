class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int helper(vector<vector<char>>& matrix, int i, int j) {
        if (i >= m || j >= n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = helper(matrix, i, j + 1);
        int down  = helper(matrix, i + 1, j);
        int diag  = helper(matrix, i + 1, j + 1);

        if (matrix[i][j] == '1') {
            dp[i][j] = 1 + min({right, down, diag});
        } else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, -1));

        int maxSide = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxSide = max(maxSide, helper(matrix, i, j));
            }
        }
        return maxSide * maxSide; // return area
    }
};
