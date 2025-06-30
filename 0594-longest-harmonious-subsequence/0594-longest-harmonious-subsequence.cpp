class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;

        int result = 0;
        
        for(int right = 0;right<n;right++){
            while(nums[right]-nums[left]>1){
                left++;
            }
            if(nums[right]-nums[left]==1){
                result = max(result, right-left+1);
            }
        }
        return result; 
    }
};
