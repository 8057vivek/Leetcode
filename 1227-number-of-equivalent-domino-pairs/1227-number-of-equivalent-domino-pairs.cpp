class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
        for(vector<int>& vec : dom){
            sort(vec.begin(), vec.end());
        }
        sort(dom.begin(), dom.end());

        int count = 1;
        int res = 0;
        for(int i=1;i<dom.size();i++){
            if(dom[i]==dom[i-1]){
                count++;
            }
            else{
                if(count>1){
                    res = res + (count*(count-1))/2;
                }
                count=1;
            }
        }
        if(count>1){
            res = res + (count*(count-1))/2;
        }
        return res;
    }
};