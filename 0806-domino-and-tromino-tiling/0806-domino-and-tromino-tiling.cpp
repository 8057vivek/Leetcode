class Solution {
public:
    int numTilings(int n) {
        const int M = 1e9+7;
        if(n==1) return 1;
        if(n==2) return 2;
        vector<long long> vec(n+1);
        vec[0] = 1;
        vec[1] = 1;
        vec[2] = 2;
        for(int i=3;i<=n;i++){
            vec[i] = (2 * vec[i-1] + vec[i-3]) % M;
        }
        return vec[n];
    }
};