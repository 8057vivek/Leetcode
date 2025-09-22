class Solution {
public:
    int recursion(int index,int last,  vector<int>& nums, vector<vector<int>> & dp){
        if(index==nums.size()){
            return 0;
        }
        if(dp[index][last+1]!=-1){
            return dp[index][last+1];
        }
        int notTake = recursion(index+1, last, nums, dp);

        int take = 0;
        if(last==-1 || nums[index]>nums[last]){
            take = 1+recursion(index+1, index, nums, dp);
        }
        return dp[index][last+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int last = index - 1; last >= -1; last--) {
                
                int notTake = dp[index + 1][last + 1];
                int take = 0;

                if (last == -1 || nums[index] > nums[last]) {
                    take = 1 + dp[index + 1][index + 1];
                }

                dp[index][last + 1] = max(take, notTake);
            }
        }

        return dp[0][-1 + 1];
    }
};