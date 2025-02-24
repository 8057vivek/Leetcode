class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = s.length(), k = p.length();
        if (k > n) return result;

        vector<int> pCount(26, 0), sCount(26, 0);

        // Count frequency of characters in `p`
        for (char ch : p) pCount[ch - 'a']++;

        // First window of size `k`
        for (int i = 0; i < k; i++) sCount[s[i] - 'a']++;

        // Compare counts for the first window
        if (pCount == sCount) result.push_back(0);

        // Slide the window across `s`
        for (int i = k; i < n; i++) {
            sCount[s[i] - 'a']++;      // Add new character to window
            sCount[s[i - k] - 'a']--;  // Remove old character from window

            if (pCount == sCount) result.push_back(i - k + 1);
        }

        return result;
    }
};
