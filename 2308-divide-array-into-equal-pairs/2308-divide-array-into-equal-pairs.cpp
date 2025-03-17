class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int n:nums){
            map[n]++;
        }
        bool isValid = true;
        for(auto& it: map){
            if(it.second%2!=0){
                isValid = false;
            }
        }
        return isValid;
    }
};