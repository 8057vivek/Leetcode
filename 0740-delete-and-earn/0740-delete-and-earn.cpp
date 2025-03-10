class Solution {
public:
    unordered_map<int, int> dp;
    int recursion(vector<int>& freq, int index){
        if(index>=freq.size()){
            return 0;
        }
        if(dp.find(index)!=dp.end()){
            return dp[index];
        }
        int take = freq[index]+recursion(freq, index+2);
        int notTake = recursion(freq, index+1);

        return dp[index] = max(take, notTake);
    }
    int deleteAndEarn(vector<int>& nums) {

        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxElement+1,0);
        for(int num:nums){
            freq[num]+=num;
        }
        return recursion(freq,0);
        
    }
};