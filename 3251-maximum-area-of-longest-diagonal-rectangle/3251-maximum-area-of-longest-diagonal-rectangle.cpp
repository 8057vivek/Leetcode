class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int m = dimensions[0].size();

        int maxIndex = -1;
        int sum = 0;  
        int area = 0;  

        for(int i=0; i<n; i++){
            int curr = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
            int currArea = dimensions[i][0]*dimensions[i][1];

            if(curr > sum || (curr == sum && currArea > area)){
                sum = curr;
                maxIndex = i;
                area = currArea;
            }
        }
        return dimensions[maxIndex][0]*dimensions[maxIndex][1];
    }
};