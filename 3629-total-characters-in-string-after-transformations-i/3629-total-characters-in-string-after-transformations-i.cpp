class Solution {
public:  
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<int> prev(26, 1), curr(26);

        for (int k = 1; k <= t; ++k) {
            for (int c = 0; c < 26; ++c) {
                if (c == 25)
                    curr[c] = (prev[0] + prev[1]) % MOD;
                else
                    curr[c] = prev[c + 1];
            }
            prev = curr;  // move forward in time
        }

        long long result = 0;
        for (char ch : s)
            result = (result + prev[ch - 'a']) % MOD;

        return result;
    }
};