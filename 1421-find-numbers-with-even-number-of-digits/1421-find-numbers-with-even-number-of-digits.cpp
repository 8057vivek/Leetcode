class Solution {
public:
    int findNumbers(vector<int>& nums) {
        // int nums.size()
        int count = 0;
        for(int n : nums){
            string s = to_string(n);
            if(s.length()%2==0){
                count++;
            }
        }
        return count;
    }
};