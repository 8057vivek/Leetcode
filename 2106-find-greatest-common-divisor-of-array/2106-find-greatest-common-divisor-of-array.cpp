class Solution {
public:
    int gcd(int a, int b){
        if(b==0){
            return a;
        }
        if(a==0){
            return b;
        }

        if(a==b){
            return a;
        }

        if(b>a){
            return gcd(a,b-a);
        }
        return gcd(a-b,b);
    }
    int findGCD(vector<int>& nums) {
        int first =INT_MAX, last = INT_MIN;

        int n = nums.size();
        for(int i=0;i<n;i++){
            first = min(first,nums[i]);
            last = max(last,nums[i]);
        }

        return gcd(first,last);

    }
};