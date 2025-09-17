class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long prefix = 0, min_prefix = 0, max_prefix = 0;
        for (int diff : differences) {
            prefix += diff;
            min_prefix = min(min_prefix, prefix);
            max_prefix = max(max_prefix, prefix);
        }
        long long min_x = lower - min_prefix;
        long long max_x = upper - max_prefix;
        return (int)max(0LL, max_x - min_x + 1);
    }
};