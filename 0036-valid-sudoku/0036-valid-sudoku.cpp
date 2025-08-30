class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char num=board[i][j];
                if(num!='.' && isSafe(board,i,j,num)==false){
                    return false;
                }
            }
        }

        return true;
    }
    bool isSafe(vector<vector<char>>& board,int row,int col,char num){
        // row check
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i]==num){
                return false;
            }
        }
        //col check
        for(int i=0;i<9;i++){
            if(i!=row && board[i][col]==num){
                return false;
            }
        }
        //grid check
        int row_=(row/3)*3;
        int col_=(col/3)*3;
        for(int i=row_;i<row_+3;i++){
            for(int j=col_;j<col_+3;j++){
                if((i!=row || j!=col) && board[i][j]==num){
                    return false;
                }
                
            }
        }
        return true;
    }
};