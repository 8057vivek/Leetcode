class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (k > n) return 0; 

        int count = 0, invalidPairs = 0;


        for (int i = 0; i < k - 1; i++) {
            if (colors[i] == colors[i + 1]) {
                invalidPairs++;
            }
        }
        
        // If the first window is valid, count it
        if (invalidPairs == 0) count++;

        // Step 2: Slide the window across the array
        for (int i = 1; i < n; i++) {
            // Remove outgoing element's impact
            if (colors[i - 1] == colors[i]) invalidPairs--;

            // Add incoming element's impact
            if (colors[(i + k - 2) % n] == colors[(i + k - 1) % n]) invalidPairs++;

            // If valid (no invalid pairs), count it
            if (invalidPairs == 0) count++;
        }

        return count;
    }
};
