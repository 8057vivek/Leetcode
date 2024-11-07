
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int bits[32] = {0};  

        for(int num : candidates) {
            for(int j = 0; j < 32; j++) {
                if ((num & (1 << j)) != 0) {
                    bits[j]++;
                }
            }
        }
        
        int maxCount = 0;
        for(int i = 0; i < 32; i++) {
            maxCount = max(maxCount, bits[i]);
        }
        
        return maxCount;
    }
};
