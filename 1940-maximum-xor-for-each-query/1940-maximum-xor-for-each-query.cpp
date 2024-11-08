class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> result(n);

        int xor_total = 0;
        for (int num : nums) {
            xor_total ^= num;
        }

        int max_k = (1 << maximumBit) - 1;

        for (int i = 0; i < n; ++i) {
            
            result[i] = xor_total ^ max_k;

            xor_total ^= nums[n - 1 - i];
        }

        return result;
        }
};