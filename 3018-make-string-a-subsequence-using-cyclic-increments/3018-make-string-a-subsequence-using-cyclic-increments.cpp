class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx = 0;  // Pointer for str2
        for (char ch : str1) {
            // If characters match, move to the next character in str2
            if (ch == str2[idx]) {
                idx++;
            } 
            // Try to cyclically increment the character if they don't match
            else {
                if ((ch == 'z' && str2[idx] == 'a') || ch + 1 == str2[idx]) {
                    idx++;
                }
            }
            // If we have matched all characters in str2, return true
            if (idx == str2.length()) {
                return true;
            }
        }
        return false;
    }
};