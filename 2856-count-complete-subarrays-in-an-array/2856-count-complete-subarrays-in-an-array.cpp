class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_set<int> set;
        for(int n : nums){
            set.insert(n);
        }
        int length = set.size();
        int left = 0;

        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;

            while(mp.size()==length){
                count += (n-i);
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
        }

        return count;
    }
};