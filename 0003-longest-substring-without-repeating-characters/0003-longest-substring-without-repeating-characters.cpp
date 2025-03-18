class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left=0;
        int count=0;
        int maxLength = INT_MIN;
        int n = s.length();
        for(int i=0;i<n;i++){
            map[s[i]]++;

            while(map[s[i]]>1){
                map[s[left]]-=1;
                left++;
            }
             maxLength=max(i-left+1, maxLength);
        }
        if(maxLength==INT_MIN){
            return 0;
        }

        return maxLength;

    }
};