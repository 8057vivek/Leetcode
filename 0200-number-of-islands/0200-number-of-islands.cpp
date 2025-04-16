// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
        
//     }
// };

class Solution {
public:
    int dirRow[4] = {-1,0,1,0};
    int dirCol[4] = {0,1,0,-1};
    void dfs(int m, int n, int r, int c,vector<vector<char>>& board){
        board[r][c] = 'V';
        for(int i=0;i<4;i++){
            int nrow = dirRow[i]+r;
            int ncol = dirCol[i]+c;
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && board[nrow][ncol]=='1'){
                dfs(m, n,nrow, ncol, board);
            }
        }
    }
    int numIslands(vector<vector<char>>& board) {

        int m =  board.size();
        int n = board[0].size();
        int count = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='1'){
                    dfs(m, n, i, j,board);
                    count++;
                }
            }
        }

        return count;
    }
};