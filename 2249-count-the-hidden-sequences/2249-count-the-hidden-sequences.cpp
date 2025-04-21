class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long curr = 0; // starting from 0
        long maxVal = 0;
        long minVal = 0;

        for (int i = 0; i < diff.size(); i++) {
            curr += diff[i];
            maxVal = max(maxVal, curr);
            minVal = min(minVal, curr);
        }

        long range = maxVal - minVal;
        long total = upper - lower;

        if (range > total) return 0;
        return total - range + 1;
    }
};
