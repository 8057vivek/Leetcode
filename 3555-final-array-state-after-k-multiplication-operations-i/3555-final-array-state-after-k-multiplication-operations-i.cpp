class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
        // Find the index of the minimum element
        auto minIter = min_element(nums.begin(), nums.end());
        *minIter *= multiplier;
    }
    return nums;
    }
};