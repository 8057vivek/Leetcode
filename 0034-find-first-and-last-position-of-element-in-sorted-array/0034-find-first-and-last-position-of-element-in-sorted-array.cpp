class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> result(2,-1);

        int low = 0;
        int high = n-1;
        bool found = false;
        int mid = (low+high)/2;
        while(low<=high){
            
            if(nums[mid]==target){
                found = true;
                break;
            }
            if(nums[mid]>target){
                high = mid-1;
            }
            if(nums[mid]<target){
                low = mid+1;
            }
            mid = (low+high)/2;
        }

        if(!found){
            return result;
        }

        low = mid;
        high = mid;

        // for lower index
        while(low>=0 && nums[low]==target){
            low--;
        }

        while(high<n && nums[high]==target){
            high++;
        }

        result[0]=low+1;
        result[1]=high-1;

        return result;
        
    }
};