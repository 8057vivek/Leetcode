class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int last=0;
        int count=0;
        for(auto& vec : meetings){
            int first = vec[0];
            int second = vec[1];
            if(first>last){
                int diff = first-last;
                if(diff>1){
                    count +=diff-1;
                }
            }
             last = max(last, second);
        }
        int remaining = days-last;
        if(remaining>0){
            count+=remaining;
        }
        return count;
    }
};