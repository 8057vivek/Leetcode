class Solution {
public:
    string largestOddNumber(string num) {
        int n  = num.length();
        bool oddFound = false;
        int i=n-1;
        int index = 0;
        while(oddFound==false && i>=0){
            if((num[i]-'0')%2!=0){
                oddFound = true;
                index = i;
            }
            i--;
        }

        if(oddFound){
        return num.substr(0,index+1);
        }
        return "";

    }
};