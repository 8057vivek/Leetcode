class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m  = nums2.size();
        vector<int> result(n, -1);

        // stack<int> st;
        for(int i=0;i<n;i++){
           int j=0;
           while(nums2[j]!=nums1[i]){
            j++;
           }
           for(int k=j;k<m;k++){
            if(nums2[k]>nums1[i]){
                result[i] = nums2[k];
                break;
            }
           }
        }

        return result;

    }
};