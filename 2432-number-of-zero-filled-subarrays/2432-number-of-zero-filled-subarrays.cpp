class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long zeros = 0;

        for(int num : nums){
            if(num == 0){
                zeros++;
                ans += zeros;  
            } else {
                zeros = 0;  
            }
        }

        return ans;
    }
};
