class Solution {
public:
    void allPermutations(int index, vector<int>& nums, vector<int>& ans,vector<int>& visited, vector<vector<int>>& result){
        if(ans.size()==nums.size()){
            result.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                ans.push_back(nums[i]);
                visited[i]=1;
                allPermutations(i,nums,ans,visited,result);
                visited[i]=0;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> visited(nums.size(),0);
        vector<int> ans;
        allPermutations(0,nums,ans,visited,result);
        return result;
    }
};