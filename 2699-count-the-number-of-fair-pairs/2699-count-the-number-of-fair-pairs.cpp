class Solution {
public:
    long long helper(vector<int>& nums, int bound) {
        int n = nums.size();
        long long count = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            if (nums[left] + nums[right] <= bound) {
                // All elements from left+1 to right form valid pairs with nums[left]
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }

        return count;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return helper(nums, upper) - helper(nums, lower - 1);
    }
};
