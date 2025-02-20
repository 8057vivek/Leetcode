class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int res = INT_MIN;
        for(int n : nums){
            currentSum +=n;
            res = max(res, currentSum);
            if(currentSum<0){
                currentSum =0;
            }
        }
        return res;
    }
};