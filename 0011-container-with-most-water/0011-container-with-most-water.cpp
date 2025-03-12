class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = INT_MIN;

        while(left<right){
            int height1 = min(height[left],height[right]);
            int width = right-left;
            int area = height1*width;

            maxArea = max(maxArea, area);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
            
        }
        return maxArea;
    }
};