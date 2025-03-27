class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        int Ele = nums[0], count = 0;
        for(int num : nums){
            if(num==Ele){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                Ele = num;
                count = 1;
            }
        }

        int dominantCount = 0;
        for(int num : nums){
            if(num==Ele){
                dominantCount++;
            }
        }

        int leftCount = 0;
        int rightCount = dominantCount;
        for(int i=0;i<n;i++){
            if(nums[i]==Ele){
                leftCount++;
                rightCount--;

                if(leftCount*2>(i+1) && rightCount*2>(n-i-1)){
                    return i;
                }
            }
        }

        return -1;
    }
};