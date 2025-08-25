class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        map<int, vector<int>> mp;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                mp[row+col].push_back(mat[row][col]);
            }
        }

        vector<int> result;
        for(auto& it : mp){
            if(it.first % 2==0){
                int size = it.second.size();
                for(int i=size-1;i>=0;i--){
                    result.push_back(it.second[i]);
                }
            }
            else{
                for(int i=0;i<it.second.size();i++){
                    result.push_back(it.second[i]);
                }
            }
        }

        return result;
    }
};