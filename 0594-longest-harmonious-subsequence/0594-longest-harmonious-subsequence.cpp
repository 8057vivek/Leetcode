class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        unordered_map<int, int> map;
        for(int i:nums){
            map[i]++;
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                maxLen = max(maxLen,(map[nums[i]]+map[nums[i-1]]));
            }
        }

        return maxLen;
    }
};