class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (k > n) return 0; 

        int count = 0;
        bool valid = true;


        for (int i = 0; i < k - 1; i++) {
            if (colors[i % n] == colors[(i + 1) % n]) {
                valid = false;
                break;
            }
        }
        if (valid) count++;

    
        for (int i = 1; i < n; i++) {
            
            if (colors[(i - 1) % n] == colors[i % n]) valid = false;

        
            if (colors[(i + k - 2) % n] == colors[(i + k - 1) % n]) valid = false;

            
            if (valid) {
                count++;
            } else {
                
                valid = true;
                for (int j = i; j < i + k - 1; j++) {
                    if (colors[j % n] == colors[(j + 1) % n]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) count++; 
            }
        }
        return count;
    }
};
