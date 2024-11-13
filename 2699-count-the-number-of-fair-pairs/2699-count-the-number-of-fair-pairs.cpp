class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n - 1; ++i) {
            // Find the lower bound for j where nums[i] + nums[j] >= lower
            int low_j = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            
            // Find the upper bound for j where nums[i] + nums[j] <= upper
            int high_j = std::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            
            count += high_j - low_j;
        }

        return count;
    }
};