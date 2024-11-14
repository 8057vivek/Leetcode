class Solution {
public:
    int minimizedMaximum(int stores, vector<int>& productQuantities) {
        int low = 1, high = *max_element(productQuantities.begin(), productQuantities.end());
        
        while (low < high) {
            int maxProductsPerStore = low + (high - low) / 2;
            int requiredStores = 0;
            
            for (int quantity : productQuantities) {
                requiredStores += (quantity + maxProductsPerStore - 1) / maxProductsPerStore;
            }
            
            if (requiredStores <= stores) {
                high = maxProductsPerStore;
            } else {
                low = maxProductsPerStore + 1;
            }
        }
        
        return low;
    }
};
