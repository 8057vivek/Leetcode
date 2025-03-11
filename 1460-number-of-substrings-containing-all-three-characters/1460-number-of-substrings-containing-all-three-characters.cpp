class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();
        unordered_map<char, int> map;
        int  left= 0, count = 0;
        for(int right=0; right<n;right++){
            map[s[right]]++;

            while(map.size()==3){
                count+=(n-right);

                map[s[left]]--;
                if(map[s[left]]==0){
                    map.erase(s[left]);
                }
                left++;
            }
        }

        return count;
    }
};
