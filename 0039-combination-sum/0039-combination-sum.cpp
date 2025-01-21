class Solution {
public:

    void CombSum(int index,vector<int>& current, vector<int>& candidates, int target,vector<vector<int>>& result){
        if(index>=candidates.size()){
            if(target==0){
                result.push_back(current);
            }
            return;
        }

        CombSum(index+1,current,candidates,target,result);
        if(candidates[index]<= target){
            current.push_back(candidates[index]);
            CombSum(index,current,candidates,target-candidates[index],result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> curr;
        CombSum(0,curr,candidates,target,result);

        return result;
    }
};