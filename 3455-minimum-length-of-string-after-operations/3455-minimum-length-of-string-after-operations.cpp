class Solution {
public:
    int minimumLength(string s) {

        unordered_map<char, int> fMap;
        for(char ch:s){
            fMap[ch]++;
        }

        int count=0;

        for(auto& pair:fMap){
            int f = pair.second;
            if(f%2==1){
                count=count+f-1;
            }else{
                count+=f-2;
            }
        }
        return s.length()-count;
        
    }
};