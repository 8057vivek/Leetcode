class Solution {
public:
    void perfectSquares(int n, vector<int>& result){
        for(int i=1;i*i<=n;i++){
            result.push_back(i*i);
        }

    }
    int recursion(int n,vector<int>& squares, int size, int index){

        if(n == 0) return 0;
        if(n < 0 || index >= squares.size()) return INT_MAX / 2; 

        int take = 1+recursion(n-squares[index], squares, size, index);
        int notTake = recursion(n, squares, size, index+1);

        return min(take, notTake);

    }

    int numSquares(int n) {
        vector<int> squares;
        perfectSquares(n, squares);
        
        int m = squares.size();
        return recursion(n,squares, m,0);
    }
};