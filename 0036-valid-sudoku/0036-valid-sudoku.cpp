class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num == '.') continue;

                string row = to_string(i) + " in row " + num;
                string col = to_string(j) + " in col " + num;
                string box = to_string(i / 3) + to_string(j / 3) + " in box " + num;

                if (seen.count(row) || seen.count(col) || seen.count(box))
                    return false;

                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }
        return true;
    }
};
