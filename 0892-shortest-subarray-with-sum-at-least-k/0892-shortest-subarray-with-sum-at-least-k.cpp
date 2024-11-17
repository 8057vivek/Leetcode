class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq; // Deque to store indices
    vector<long long> prefixSum(n + 1, 0); // Prefix sum array
    
    // Compute prefix sums
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int minLength = INT_MAX;

    for (int i = 0; i <= n; ++i) {
        // Check for valid subarrays
        while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
            minLength = min(minLength, i - dq.front());
            dq.pop_front();
        }

        // Remove redundant indices from deque
        while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
            dq.pop_back();
        }

        // Add current index to deque
        dq.push_back(i);
    }

    return minLength == INT_MAX ? -1 : minLength;

    }
};