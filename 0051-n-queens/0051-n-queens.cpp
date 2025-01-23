class Solution {
public:
    bool isValid(int n, int row, int col, vector<vector<char>>& matrix){
        int j=col-1;
        while(j>=0){
            if(matrix[row][j]=='Q'){
                return false;
            }
            j--;
        }

        int i = row;
        j = col;
        while(i>=0 && j>=0){
            if(matrix[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        i=row;
        j=col;

        while(i<n && j>=0){
            if(matrix[i][j]=='Q'){
                return false;
            }
            i++,j--;
        }

        return true;
    }
    void nQueen(int n,int col, vector<vector<char>>& matrix, vector<vector<string>>& result){
        if (col == n) {
            vector<string> solution;
            for(int i=0;i<n;i++){
                string s = "";
                for(int j=0;j<n;j++){
                    s.push_back(matrix[i][j]);
                }
                solution.push_back(s);
            }
            result.push_back(solution);
            return;
        }
        for(int row=0;row<n;row++){
            if(isValid(n,row,col,matrix)){
                matrix[row][col]='Q';
            nQueen(n,col+1,matrix,result);
            matrix[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> matrix(n,vector<char>(n,'.'));

        vector<vector<string>> result;

        nQueen(n,0,matrix,result);

        return result;
    }
};