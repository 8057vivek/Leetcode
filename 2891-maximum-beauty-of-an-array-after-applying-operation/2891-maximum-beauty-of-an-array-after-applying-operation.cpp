class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

    int n = nums.size();
    int start = 0, maxBeauty = 0;

    // Sliding window
    for (int end = 0; end < n; ++end) {
        // Shrink the window if condition is not met
        while (nums[end] - nums[start] > 2 * k) {
            start++;
        }
        // Update the maximum beauty
        maxBeauty = max(maxBeauty, end - start + 1);
    }

    return maxBeauty;
    }
};