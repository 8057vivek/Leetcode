class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        unordered_map<int,int> map;

        for(int i=0;i<n;i++){
           map[nums[i]] = i;
        }

        vector<int> result;
        for(int i=0;i<n;i++){
            
            int Val = target-nums[i];
            if(map.find(Val)!=map.end() && map[Val] != i){
                result.push_back(i);
                result.push_back(map[Val]);
                return result;
            }
        }

        return result;
    }
};