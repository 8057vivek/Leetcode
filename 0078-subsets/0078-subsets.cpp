class Solution {
public:
    void fun(int index,vector<int> nums, vector<vector<int>>& res, vector<int>& curr){
        if(index>=nums.size()){
            res.push_back(curr);
            return;
        }

        fun(index+1,nums,res,curr);

        curr.push_back(nums[index]);
        fun(index+1,nums,res,curr);

        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        
        fun(0,nums,res,curr);

        return res;
    }
};