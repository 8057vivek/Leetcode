class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        vector<int>count(n+1);
        for(vector<int> vec : trust){
            int a = vec[0];
            int b = vec[1];

            count[a]--;
            count[b]++;
        }

        for(int i=0;i<=n;i++){
            if(count[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};