class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> indexArray;
        for(int i=0;i<n;i++){
            indexArray.push_back({nums[i], i});
        }
        sort(indexArray.begin(), indexArray.end());
        int start = n-k;
        int end = n;
        sort(indexArray.begin()+start,indexArray.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second<b.second;
        });
        vector<int> result;
        for(int i=start;i<end;i++){
            result.push_back(indexArray[i].first);
        }
        return result;
    }
};