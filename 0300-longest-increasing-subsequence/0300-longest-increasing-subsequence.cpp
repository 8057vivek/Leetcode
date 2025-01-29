class Solution {
public:
    int recursion(int i,int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int Nottake = recursion(i+1,prev,nums,dp);
        int take=0;
        if(prev==-1 || nums[i]>nums[prev]){
            take = 1+recursion(i+1,i,nums,dp);
        }

        return dp[i][prev+1] = max(take, Nottake);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return recursion(0,-1,nums,dp);
    }
};