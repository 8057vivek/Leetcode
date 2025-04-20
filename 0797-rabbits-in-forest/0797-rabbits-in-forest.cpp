class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;

        for(int i : answers){
            mp[i]++;
        }

        int count = 0;

        for(auto& [number,f] : mp){
            int groups = (f + (number+1) - 1) / (number+1);
            count += groups * (number+1);
        }
        return count;
    }

};