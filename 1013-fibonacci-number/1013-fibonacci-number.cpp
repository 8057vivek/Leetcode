class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        int prev=1;
        int pprev=1;
        int curr=prev;
        for(int i=2;i<n;i++){
            curr = prev+pprev;
            pprev = prev;
            prev = curr;
        }
        return curr;
    }
};