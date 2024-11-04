class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        string res = s+s;
        return res.find(goal) != string::npos;
    }
};
