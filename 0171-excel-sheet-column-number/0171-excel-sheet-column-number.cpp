class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long count = 0;

        for(char s : columnTitle){
            count = count * 26 + s-'A'+1;
        }

        return count;
        
    }
};