class Solution {
public:
    int tabulation(string text1, string text2){
        int m = text1.length();
        int n = text2.length();

        vector<int> curr(n + 1, 0), next(n + 1, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;
        }

        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return tabulation(text1,text2);
    }
};