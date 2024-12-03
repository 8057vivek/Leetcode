class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int prev = 0;

        for (int i = 0; i < spaces.size(); i++) {
            result.append(s.substr(prev, spaces[i] - prev));
            result += " ";
            prev = spaces[i];
        }

        result.append(s.substr(prev));
        return result; 
    }
    
};