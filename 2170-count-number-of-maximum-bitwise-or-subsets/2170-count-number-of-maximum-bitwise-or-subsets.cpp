class Solution {
public:

    int noOfMaxOrSubsets(int currOr, int index, int n, vector<int>& nums, int maxOr){
        if(index>=n){
            if(currOr==maxOr){
                return 1;
            }
            else{
                return 0;
            }
        }

        int takeCount = noOfMaxOrSubsets(currOr|nums[index],index+1, n, nums, maxOr);
        int notTakeCount = noOfMaxOrSubsets(currOr, index+1, n , nums,maxOr);

        return takeCount+notTakeCount;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for(int i=0;i<n;i++){
            maxOr = maxOr|nums[i];
        }
        return noOfMaxOrSubsets(0, 0,n,nums,maxOr);
    }
};