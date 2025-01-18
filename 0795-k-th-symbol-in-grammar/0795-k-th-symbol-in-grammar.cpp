class Solution {
public:
    int kthGrammar(int n, int k) {
        
        int count = 0;
        k--; 
        while (k > 0) {
            count += (k & 1); // Check if the least significant bit is 1
            k >>= 1;          // Right shift to process the next bit
        }
        return count % 2; // If odd, return 1; if even, return 0
    }
};