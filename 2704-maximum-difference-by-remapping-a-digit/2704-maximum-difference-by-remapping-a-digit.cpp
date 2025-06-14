class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string max_s = s, min_s = s;
        
        for (char ch : s) {
            if (ch != '9') {
                for (char& c : max_s) {
                    if (c == ch) c = '9';
                }
                break;
            }
        }
        for (char ch : s) {
            if (ch != '0') {
                for (char& c : min_s) {
                    if (c == ch) c = '0';
                }
                break;
            }
        }

        int max_val = stoi(max_s);
        int min_val = stoi(min_s);
        return max_val - min_val;
    }
};
