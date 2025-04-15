class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& grid, int m, int n, int dirRow[], int dirCol[], int &count) {
        grid[sr][sc] = 2;  // Mark visited

        for (int i = 0; i < 4; i++) {
            int nrow = sr + dirRow[i];
            int ncol = sc + dirCol[i];

    
            if (nrow < 0 || ncol < 0 || nrow >= m || ncol >= n || grid[nrow][ncol] == 0) {
                count++;
            }
    
            else if (grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, m, n, dirRow, dirCol, count);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dirRow[] = {0, 1, 0, -1};
        int dirCol[] = {1, 0, -1, 0};
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, m, n, dirRow, dirCol, count);
                    return count;
                }
            }
        }

        return 0; 
    }
};
