class Solution {
public:
    int maximumCount(vector<int>& nums) {
        nums.push_back(INT_MAX);

        int n = nums.size();
        int negative = 0;
        int positive = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i]<0){
                negative++;
            }else if(nums[i]>0){
                positive++;
            }
        }
        return max(negative, positive);
    }
};