class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(int num : nums){
            map[num]++;
        }

        int result = 0;
        int countNegative =0;
        bool zero = false;
        int maximum = -101;

        for(auto& it:map){
            if(it.first>0){
                result+=it.first;
            }
            else if(it.first==0){
                zero=true;
            }
            else{
                countNegative++;
            }
            maximum=max(maximum, it.first);
        }

        if(result==0 && zero){
            return 0;
        }
        if(result==0){
            return maximum;
        }

        return result;

    }
};