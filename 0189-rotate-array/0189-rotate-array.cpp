class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 
        vector<int> result(n);
        
        int j=n-k;
        for(int i=0;i<k;i++){
            result[i]=nums[j];
            j++;
            
        }
        int l=0;
        for(int i=k;i<n;i++){
            result[i]=nums[l];
            l++;
        }
        nums=result;
    }
};