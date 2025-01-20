class Solution {
public:

    void combination(int idx,string cmb, unordered_map<char, string> map,vector<string> & res, string digits){
        if(idx>=digits.size()){
            res.push_back(cmb);
            return;
        }

        string temp = map[digits[idx]];
        for(int i=0;i<temp.size();i++){
            char p = temp[i];
            cmb.push_back(p);
            combination(idx+1,cmb,map,res,digits);
            cmb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        unordered_map<char, string> map = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> res;

        if(digits.length()==0){
            return res;
        }
        string cmb = "";
        combination(0,cmb,map,res,digits);

        return res;
    }
};