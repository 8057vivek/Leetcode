class Solution {
public:
    string frequencySort(string s) {
        vector<vector<char>> bucket(s.size()+1);
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        for(auto& p : mp){
            bucket[p.second].push_back(p.first);
        }

        string res = "";
        for(int i=bucket.size()-1;i>=1;i--){
            for(char c : bucket[i]){
                res+=string(i, c);
            }
        }
        return res;
    }
};