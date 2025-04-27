class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        for(int i=0;i<n-2;i++){
            int c = 0;
            int sum = 0;
            int sub = 0;
            for(int j=i;j<i+3;j++){
                if(c==0 || c==2){
                    sum+=arr[j];
                }
                if(c==1){
                    sub = arr[j];
                }
                c++;
            }
            if(sum*2==sub){
                count++;
            }
        }
        return count;
    }
};