class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        
        int n  = diff.size();
        vector<long> vec(n+1);
        vec[0] = diff[0];
        for(int i=1;i<=n;i++){
            vec[i] = vec[i-1]+diff[i-1];
        }

        sort(vec.begin(),vec.end());
        int range = vec[n] - vec[0];
        int res = upper-lower+1-(range);

        if(res<0){
            return 0;
        }
        return res;

    }
};