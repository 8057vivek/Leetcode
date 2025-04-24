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

        for(int i=0;i<n;i++){
            
            unordered_map<int, int> mp;
            int index = 0;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                if(mp.size()==length){
                    index = j;
                    count = count + (n-index);
                    break;
                }
                
            }
        }

        return count;
    }
};