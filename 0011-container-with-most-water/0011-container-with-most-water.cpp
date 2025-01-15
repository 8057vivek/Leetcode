class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j = height.size()-1;
        int ans = INT_MIN;
        while(i<j){
            int length = min(height[i],height[j]);
            int width = j-i;
            int area = length*width;
            ans=max(ans,area);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};