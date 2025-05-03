class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotateTop = 0;
        int rotateBottom = 0;
        int n = tops.size();

        for (int i = 0; i < n; i++) {
            // If the target is not in either top or bottom, it's not possible
            if (tops[i] != target && bottoms[i] != target)
                return -1;

            // Count how many rotations needed to bring target to top
            if (tops[i] != target)
                rotateTop++;

            // Count how many rotations needed to bring target to bottom
            if (bottoms[i] != target)
                rotateBottom++;
        }

        return min(rotateTop, rotateBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans1 = check(tops[0], tops, bottoms);
        int ans2 = check(bottoms[0], tops, bottoms);

        // If both are valid, return the smaller one
        if (ans1 != -1 && ans2 != -1)
            return min(ans1, ans2);

        // If only one is valid, return that
        if (ans1 != -1) return ans1;
        if (ans2 != -1) return ans2;

        // If neither works
        return -1;
    }
};
