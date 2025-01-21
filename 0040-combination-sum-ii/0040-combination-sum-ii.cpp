class Solution {
public:
    void comb(int index, vector<int> & current, vector<int>& candidates, int target,vector<vector<int>> & result){
            if(target==0){
                result.push_back(current);
                return;
            }

            for(int i=index;i<candidates.size();i++){

                if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
                }
                if(candidates[i]<=target){
                    current.push_back(candidates[i]);
                    comb(i+1,current,candidates,target-candidates[i],result);
                    current.pop_back();
                }
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        comb(0,current,candidates,target,result);

        return result;
    }
};