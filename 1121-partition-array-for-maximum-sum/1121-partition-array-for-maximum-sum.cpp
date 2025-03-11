class Solution {
public:
    int recursion(vector<int>& arr, int k, int index,vector<int>& dp){

        if(index>=arr.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int maxSum =INT_MIN;
        int maxElement = INT_MIN;
        for(int i=0;i<k and index+i <arr.size();i++){
            maxElement = max(maxElement, arr[index+i]);
            int sum = (i+1) *  maxElement + recursion(arr, k, index+i+1,dp);
            maxSum = max(sum, maxSum);
        }
        return dp[index] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, -1);
        return recursion(arr, k, 0,dp);
    }
};