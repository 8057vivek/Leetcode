class Solution {
public:
    void valid(int n,string str,int open, int close, vector<string>& result){
        if(open==0 && close==0){
            result.push_back(str);
            return;
        }
        if(open>0){
            str.push_back('(');
            valid(n,str,open-1, close, result);
            str.pop_back();
        }
        if(close>open){
            str.push_back(')');
            valid(n,str,open,close-1,result);
            str.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close =n;
        string str="";
        vector<string> result;
        valid(n,str, open, close,result);

        return result;
    }
};