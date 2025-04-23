class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int , char>> pq;
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        for(auto& p : mp){
            pair<int, char> pr= {p.second, p.first};
            pq.push(pr);
        }
        string res = "";
        while(!pq.empty()){
            int n = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            for(int i=0;i<n;i++){
                res+=c;
            }
        }
        return res;
    }
};