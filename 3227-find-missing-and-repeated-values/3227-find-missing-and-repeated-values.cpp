class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        vector<int> result(2);
        int n = grid.size();

        unordered_map<int, int> map;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map[grid[i][j]]++;
            }
        }

        int m = n*n;
        int actual = 0;
        int expectedSum = (m*(m+1))/2;
        for(auto const& pair : map){
            actual+=pair.first;
            if(pair.second == 2){
                result[0]=pair.first;
            }
        }
        result[1]=expectedSum-actual;

        return result;
    }
};