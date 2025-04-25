class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        vector<int> prefix(n,0);
        if(nums[0]%modulo==k){
            prefix[0]=1;
        }
        int cnt = prefix[0];
        for(int i=1;i<n;i++){
            if(nums[i]%modulo==k){
                prefix[i] = prefix[i-1]+1;
                cnt = prefix[i];
            }else{
                prefix[i] = prefix[i-1];
            }
        }
        unordered_map<int, long long> modCount;
        modCount[0] = 1;

        long long count = 0;

        for (int i = 0; i < n; i++) {
            int currMod = prefix[i] % modulo;
            int targetMod = (currMod - k + modulo) % modulo;

            if (modCount.find(targetMod) != modCount.end()) {
                count += modCount[targetMod];
            }

            modCount[currMod]++;
        }

        return count;

    }
};