class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(), candies.end()), res = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long count = 0;
            
            for (int c : candies) count += c / mid; 
            
            if (count >= k) { 
                res = mid;  
                low = mid + 1;  
            } else {
                high = mid - 1; 
            }
        }
        return res;
    }
};