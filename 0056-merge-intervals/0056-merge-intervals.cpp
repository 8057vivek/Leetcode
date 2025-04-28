class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back({intervals[0][0], intervals[0][1]});
        for(const auto& it : intervals){
            int size = result.size();
            if(result[size-1][1]>=it[0]){
                result[size-1][1] = max(it[1],result[size-1][1]);
            }
            else{
                result.push_back({it[0], it[1]});
            }
        }

        return result;
        
    }
};