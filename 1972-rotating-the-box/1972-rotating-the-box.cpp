class Solution {
public:

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int n = box.size();    // Number of rows in the original box
        int m = box[0].size(); // Number of columns in the original box

         for (int i = 0; i < n; i++) {
            int emptySpot = m - 1; // Start from the rightmost position
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    emptySpot = j - 1; // Update empty spot after an obstacle
                } else if (box[i][j] == '#') {
                    // Move stone to the nearest empty spot
                    box[i][j] = '.';
                    box[i][emptySpot--] = '#';
                }
            }
        }

        vector<vector<char>> rotated(m, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotated[j][n - i - 1] = box[i][j];
            }
        }

        return rotated;

    }
};