class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> windowSet; // To check distinct elements
    long long currentSum = 0, maxSum = 0, left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        // Add the current element to the window
        while (windowSet.count(nums[right])) {
            // Remove the leftmost element until nums[right] becomes unique
            windowSet.erase(nums[left]);
            currentSum -= nums[left];
            ++left;
        }

        windowSet.insert(nums[right]);
        currentSum += nums[right];

        // Check if the window is of size k
        if (right - left + 1 == k) {
            maxSum = max(maxSum, currentSum);
            // Slide the window forward
            windowSet.erase(nums[left]);
            currentSum -= nums[left];
            ++left;
        }
    }

    return maxSum;
    }
};