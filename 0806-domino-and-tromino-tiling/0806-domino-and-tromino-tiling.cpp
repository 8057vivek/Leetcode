class Solution {
public:
    int numTilings(int n) {
        const int M = 1e9+7;
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> vec(n+1);
        vec[0] = 1;
        vec[1] = 1;
        vec[2] = 2;
        vec[3] = 5;
        for(int i=4;i<=n;i++){
            vec[i] = ((long long)vec[i-1] *2 + (long long) vec[i-3]) % M;
        }
        return vec[n];
    }
};