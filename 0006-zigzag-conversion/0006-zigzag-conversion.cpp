class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; 

        vector<string> rows(min(numRows, int(s.size())));
        int row = 0;
        bool down = false;

        for (char c : s) {
            rows[row] += c;
            // Change direction at top or bottom
            if (row == 0 || row == numRows - 1)
                down = !down;
            row += down ? 1 : -1;
        }

        string result;
        for (string r : rows)
            result += r;

        return result;
    }
};