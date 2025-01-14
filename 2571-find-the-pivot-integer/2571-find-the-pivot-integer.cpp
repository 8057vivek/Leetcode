class Solution {
public:
    int pivotInteger(int n) {
        
        int totalSum = (n*(n+1))/2;
        int prefixSum = 0;

        for(int i=1;i<=n;i++){
            prefixSum+=i;
            if(prefixSum==totalSum){
                return i;
            }
            totalSum-=i;
        }
        
        return -1;
    }
};