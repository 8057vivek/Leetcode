class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        int first = intervals[0][0];
        int second = intervals[0][1];

        int size = 0;

        int n = intervals.size();
        for(int i=1;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start<=second){
                // result[size][0]=min(first, start);
                result[size][1]=max(second, end);
                first = result[size][0];
                second = result[size][1];
                // vector<int> vec;
                // vec.push_back(min(first, start));
                // vec.push_back(max(second, end));
                // result.push
            }else{
            vector<int> vec;
            vec.push_back(start);
            vec.push_back(end);
            result.push_back(vec);
            first = start;
            second = end;
            size++; 
            }
        }

        return result;
    }
};