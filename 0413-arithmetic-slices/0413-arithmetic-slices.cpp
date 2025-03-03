class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        if (n < 3) return 0; // No arithmetic slice possible

        int totalSlices = 0;
        int count = 0; // Stores slices ending at index i

        for (int i = 0; i < n-2; i++) {
            if (nums[i+1] - nums[i] == nums[i + 2] - nums[i+1]) {
                count += 1; // Extending the previous slice
                totalSlices += count; // Add all possible new slices
            } else {
                count = 0; // Reset count when difference breaks
            }
        }

        return totalSlices;                          
    }
};