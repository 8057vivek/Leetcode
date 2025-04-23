class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp; // freq, count
        int maximum = 0;
        for(int i=1;i<=n;i++){
            int sum = 0;
            int num = i;
            while(num>0){
                int digit = num%10;
                num = num/10;
                sum+=digit;
            }
            mp[sum]++;
            maximum = max(maximum, mp[sum]);
        }
        int count = 0;
        for(auto& pair : mp){
            if(pair.second==maximum){
                count++;
            }
        }
        return count;
    }
};