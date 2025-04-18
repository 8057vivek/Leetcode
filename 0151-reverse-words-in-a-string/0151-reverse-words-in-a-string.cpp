class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        string word = "";
        
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    vec.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        
        if (!word.empty()) {
            vec.push_back(word);
        }

        reverse(vec.begin(), vec.end());


        string res = "";
        for (int i = 0; i < vec.size(); ++i) {
            res += vec[i];
            if (i != vec.size() - 1) {
                res += " ";
            }
        }

        return res;
    }
};