class Solution {
public:
    int  merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < result.back()[1]) {

                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                
                result.emplace_back(intervals[i]);
                
            }
        }
        return result.size();
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> X;
        vector<vector<int>> Y;

        for(vector<int>& vec : rectangles){
            X.push_back({vec[0],vec[2]});
            Y.push_back({vec[1],vec[3]});
    
        }
        
        int XSize = merge(X);
        int YSize = merge(Y);

        
        return (XSize >=3 || YSize >=3);
    }
};