class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int pairs = 0;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                pairs++;
            }
        }
        return pairs+1;
    }
};