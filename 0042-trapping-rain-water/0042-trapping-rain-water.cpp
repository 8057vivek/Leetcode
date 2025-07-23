class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2){
            return 0;
        }

        vector<int> prefixWater;
        vector<int> SuffixWater(n-2);

        int maxLeft = height[0];
        int maxRight = height[n-1];

        int water = 0;

        for(int i=1;i<n-1;i++){
            maxLeft = max(maxLeft, height[i]);
            prefixWater.push_back(maxLeft-height[i]);
        }

        for(int i=n-2;i>0;i--){
            int j=n-2;
            maxRight = max(maxRight, height[i]);
            SuffixWater[i-1]=maxRight-height[i];
        }

        for(int i=0;i<prefixWater.size();i++){
            water += min(prefixWater[i],SuffixWater[i]);
        }

        return water;
    }
};