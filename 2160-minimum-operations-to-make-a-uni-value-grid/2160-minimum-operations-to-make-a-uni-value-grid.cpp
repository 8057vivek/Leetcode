class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> result;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result.push_back(grid[i][j]);
            }
        }

        int size = result.size();
        sort(result.begin(), result.end());
        int median = result[size/2];
        int count=0;

        for(int& num : result){
            if(num%x!=median%x){
                return -1;
            }
            count+=abs(median-num)/x;
        }

        return count;
    }
};