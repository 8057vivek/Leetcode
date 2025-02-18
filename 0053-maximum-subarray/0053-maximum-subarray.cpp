class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxEnd = nums[0];
        int res = nums[0];

        int n = nums.size();

        for(int i=1;i<n;i++){

            maxEnd = max(maxEnd + nums[i], nums[i]);

            res = max(res, maxEnd);
        }

        return res;
    }
};