class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        string result;
        if(numFriends==1){
            return word;
        }

        int longestPossible = n-(numFriends-1);
        for(int i=0;i<n;i++){
            int canTakeLength = min(longestPossible, n-1);
            result = max(result, word.substr(i, canTakeLength));
        }
        return result;
    }
};