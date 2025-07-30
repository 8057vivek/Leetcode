class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxAnd = INT_MIN;
        int index = -1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxAnd){
                index = i;
                maxAnd = nums[i];
            }
        }
        int result = 0;
        int length = 0;
        for(int i=index;i<n;i++){
            if(nums[i] == maxAnd ){
                length++;
                result = max(length, result);
            }else{
                length = 0;
            }
        }

        return result;
        
    }
};