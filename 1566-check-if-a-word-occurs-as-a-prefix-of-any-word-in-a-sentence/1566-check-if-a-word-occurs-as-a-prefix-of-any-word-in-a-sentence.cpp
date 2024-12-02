class Solution {
public:
    void split(vector<string>& vec, string sentence){
        stringstream ss(sentence);
        string word;
        while(ss>>word){
            vec.push_back(word);
        }
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>result;

        split(result,sentence);
        for(int i=0;i<result.size();i++){
            if(result[i].find(searchWord)==0){
                return i+1;
            }
        }

        return -1;
    }
};