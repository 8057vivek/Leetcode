class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), result(n);

        prefix[0] = nums[0];
        for (int i=1;i<n;i++) {
            prefix[i]=prefix[i - 1] + nums[i];
        }

        for (int i=0;i<n;i++) {
            int left = 0;
            int right = 0;
            if (i > 0) {
                left = nums[i] * i - prefix[i - 1];
            }
            if (i < n - 1) {
                right = (prefix[n - 1]-prefix[i]) - nums[i]*(n-i-1);
            }
            result[i] = left+right;
        }

        return result;
    }
};