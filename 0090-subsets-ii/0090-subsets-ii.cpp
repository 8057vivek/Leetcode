class Solution {
public:
    void subsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result){
         result.push_back(current);

        for (int i = index; i < nums.size(); ++i) {
            if (i != index && nums[i] == nums[i - 1]){
                continue;
            }
            current.push_back(nums[i]);
            subsets(i + 1, nums, current, result);
            current.pop_back(); 
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       vector<vector<int>> result;
       vector<int> current;
       subsets(0,nums,current,result);
       return result;
    }
};