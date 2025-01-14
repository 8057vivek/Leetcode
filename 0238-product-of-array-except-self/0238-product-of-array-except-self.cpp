class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // vector<int> prefix(n,1);
        // vector<int> suffix(n,1);

        // for(int i=1;i<n;i++){
        //     prefix[i]=nums[i-1]*prefix[i-1];
        // }

        // for(int i=n-2;i>=0;i--){
        //     suffix[i]=nums[i+1]*suffix[i+1];
        // }

        vector<int> result(n,1);
        for(int i=1;i<n;i++){
            result[i]=nums[i-1]*result[i-1];
        }

        int right = 1;
        for(int i=n-1;i>=0;i--){
            result[i]=result[i]*right;
            right *= nums[i];
        }

        return result;
    }
};