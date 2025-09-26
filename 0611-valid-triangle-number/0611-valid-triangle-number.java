class Solution {
    public int binarySearch(int [] nums, int left, int right, int target){
        int k = -1;

        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid] < target){
                k = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return k;
    }
    public int triangleNumber(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);

        int count = 0;
        for(int i=0;i<n-2;i++){
            
            for(int j = i+1;j<n-1;j++){
                int sum = nums[i]+nums[j];
                int  k = binarySearch(nums, j+1, n-1, sum);
                if(k!=-1){
                    count += (k-j);
                }
            }
        }
        return count;
    }
}