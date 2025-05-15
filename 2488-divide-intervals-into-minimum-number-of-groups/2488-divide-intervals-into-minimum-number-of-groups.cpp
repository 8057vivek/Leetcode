class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> timeline;

        for(auto& interval : intervals){
            timeline[interval[0]]++;
            timeline[interval[1]+1]--;
        }

        int maxGroups = 0;
        int currentGroups = 0;

        for(auto&[time, count] : timeline){
            currentGroups+=count;
            maxGroups = max(maxGroups, currentGroups);
        }
        return maxGroups;
    }
};