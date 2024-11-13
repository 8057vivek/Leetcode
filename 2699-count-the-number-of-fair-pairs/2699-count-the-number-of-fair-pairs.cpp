class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n - 1; ++i) {
     
            int low_j = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            
            int high_j = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            
            count += high_j - low_j;
        }

        return count;
    }
};