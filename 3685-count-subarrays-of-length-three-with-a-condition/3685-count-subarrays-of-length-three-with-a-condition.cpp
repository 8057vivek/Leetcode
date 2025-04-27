class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        for(int i=0;i<n-2;i++){
            if((arr[i]+arr[i+2])*2 == arr[i+1]){
                count++;
            }
        }
        return count;
    }
};