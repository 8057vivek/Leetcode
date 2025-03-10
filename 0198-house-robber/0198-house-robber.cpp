class Solution {
public:
    int recursion(vector<int>& nums, int index,vector<int>& dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int take = nums[index]+recursion(nums, index+2,dp);
        int notTake = recursion(nums, index+1,dp);
        return dp[index] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return recursion(nums, 0,dp);
    }
};