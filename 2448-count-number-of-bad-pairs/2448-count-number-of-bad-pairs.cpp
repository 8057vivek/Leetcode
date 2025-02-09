class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> freq;
        long long n = nums.size();
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            goodPairs += freq[key]; 
            freq[key]++;
        }

        long long totalPairs = (n * (n - 1)) / 2;
        return totalPairs - goodPairs;
        }
};