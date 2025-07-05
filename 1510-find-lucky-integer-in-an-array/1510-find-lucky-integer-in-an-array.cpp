class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> map;

        for(int i:arr){
            map[i]++;
        }

        int luckyNumber = -1;
        for(auto& it : map){
            if(it.first==it.second && it.first>luckyNumber){
                luckyNumber=it.first;
            }
        }

        return luckyNumber;

    }
};