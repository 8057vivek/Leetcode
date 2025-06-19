class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int count =0;
        int minimum = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<minimum){
                minimum=nums[i];
            }
            if(nums[i]>minimum+k){
                minimum = nums[i];
                count++;
            }
        }

        return count+1;
    }
};