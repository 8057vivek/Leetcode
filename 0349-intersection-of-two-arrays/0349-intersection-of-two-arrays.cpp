class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        unordered_set<int> res;

        for(int i=0;i<nums2.size();i++){
            if(set.count(nums2[i])){
                res.insert(nums2[i]);
            }
        }

        vector<int> result(res.begin(), res.end());

        return result;
    }
};