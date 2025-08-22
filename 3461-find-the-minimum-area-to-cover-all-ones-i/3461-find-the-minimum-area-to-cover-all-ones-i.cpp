class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int rmin = INT_MAX;
        int rmax = INT_MIN;
        int cmin = INT_MAX;
        int cmax = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    rmin = min(i, rmin);
                    rmax = max(i, rmax);
                    cmin = min(j, cmin);
                    cmax = max(j, cmax);
                }
            }
        }
        int height = rmax-rmin+1;
        int width = cmax-cmin+1;
        return height*width;
    }
};