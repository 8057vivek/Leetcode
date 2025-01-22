class Solution {
public:
    void Sum(int index, int k, int target, vector<int>& current, vector<vector<int>>& result){
            if(current.size()==k){
                if(target==0){
                    result.push_back(current);
                    return;
                }
            }
            if(index>9){
                return ;
            }
            current.push_back(index);
            Sum(index+1,k,target-index,current,result);
            current.pop_back();
            Sum(index+1, k, target,current,result);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        Sum(1,k,n,current,result);

        return result;
    }
};