class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(string s : strs){
            string a = s;
            sort(a.begin(), a.end());
            map[a].push_back(s);
        }

        vector<vector<string>> res;

        for(auto& m : map){
            res.push_back(m.second);
        }

        return res;
    }

};