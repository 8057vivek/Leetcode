class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;

    for (const auto& row : matrix) {
        string pattern = "", complement = "";
        for (int val : row) {
            pattern += to_string(val);
            complement += to_string(1 - val); // Complementary pattern
        }
        patternCount[pattern]++;
        patternCount[complement]++;
    }

    int maxRows = 0;
    for (const auto& [pattern, count] : patternCount) {
        maxRows = max(maxRows, count);
    }

    return maxRows;
    }
};