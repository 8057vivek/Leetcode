class Solution {
public:
    int recursion(vector<int>& nums, int index, vector<int>& dp, int n){
        if(index>n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }

        int steal = nums[index]+recursion(nums, index+2, dp,n);
        int skip = recursion(nums, index+1, dp, n);

        dp[index] = max(steal, skip);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(n, -1), dp2(n, -1);
        int case1 = recursion(nums,0, dp1, n-2);
        int case2 = recursion(nums, 1, dp2, n-1);

        return max(case1, case2);
    }
};