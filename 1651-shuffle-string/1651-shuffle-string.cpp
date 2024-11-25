class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        string newString(n,'*');
        for(int i=0;i<n;i++){
            int k = indices[i];
            newString[k]=s[i];
        }
        
        return newString;
    }
};