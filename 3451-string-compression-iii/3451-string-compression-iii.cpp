class Solution {
public:
    string compressedString(string s) {
        int count = 1;
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && s[i] == s[i + 1] && count < 9) {
                count++;
            } else {
                res += to_string(count) + s[i];
                count = 1;
            }
        }
        return res;
    }
};
