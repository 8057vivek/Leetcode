class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> map;
        int req = t.length();
        for (char c : t) {
            map[c]++;
        }

        int i = 0;          
        int j = 0;          
        int k = 0;         
        int minLength = INT_MAX; 

        while (j < s.length()) {
            if (map[s[j]] > 0) {
                req--;
            }
            map[s[j]]--;
            j++;

            while (req == 0) {
                if (j - i < minLength) {
                    k = i;
                    minLength = j - i;
                }

                map[s[i]]++;
                if (map[s[i]] > 0) {
                    req++;
                }
                i++;
            }
        }

        if(minLength==INT_MAX){
            return "";
        }
        return s.substr(k, minLength);
    }
};
