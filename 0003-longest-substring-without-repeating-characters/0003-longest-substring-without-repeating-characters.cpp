class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();;
        int maxLength = 0;
        for(int i=0;i<n;i++){
            vector<bool> visited(256, false);

            for(int j=i;j<n;j++){
                if(visited[s[j]]==true){
                    break;
                }else{
                    visited[s[j]]=true;
                    maxLength = max(maxLength, j-i+1);
                }
            }
        }
        return maxLength;
    }
};