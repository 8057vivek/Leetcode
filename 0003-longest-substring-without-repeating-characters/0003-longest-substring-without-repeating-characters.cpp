class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> chars;
        int left = 0, maxLength = 0;

        for (int right = 0; right < n; right++) {
            // If duplicate found, shrink the window
            while (chars.find(s[right]) != chars.end()) {
                chars.erase(s[left]);
                left++;
            }

            chars.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};