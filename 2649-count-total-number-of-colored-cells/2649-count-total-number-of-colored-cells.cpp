class Solution {
public:
    long long coloredCells(int n) {
        long long result = 0;
        result = result + ((long long)n * n) + ((long long)(n - 1) * (n - 1));
        return result;
    }
};