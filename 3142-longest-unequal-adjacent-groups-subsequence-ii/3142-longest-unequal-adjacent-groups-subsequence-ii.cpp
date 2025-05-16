class Solution {
public:
    bool validHammingDistance(string& a, string& b){
        if(a.size()!=b.size()){
            return false;
        }
        int diff= 0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                diff++;
            }
            if(diff>1){
                return false;
            }
        }
        return diff==1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);       // Longest sequence ending at index i
        vector<int> prev(n, -1);    // To reconstruct the path
        int maxIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && validHammingDistance(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        // Build the answer sequence using prev[]
        vector<string> result;
        int i = maxIndex;
        while (i != -1) {
            result.push_back(words[i]);
            i = prev[i];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};