class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix=strs[0];
        for(int i=1;i<n;i++){
            int ilen = strs[i].length();
            string pre = "";
            int len = min(ilen, static_cast<int>(prefix.length()));
            for(int j=0;j<len;j++){
                if(strs[i][j]!=prefix[j]){
                    break;
                }
                pre = pre+strs[i][j];
            }
            prefix = pre;
        }

        return prefix;
    }
};