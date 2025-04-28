class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int res = INT_MIN;
        while(left<=right){
            int area = (right-left)*min(height[left], height[right]);
            res = max(res, area);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
};