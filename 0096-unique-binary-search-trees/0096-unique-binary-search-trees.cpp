class Solution {
public:
    int recursion(int n){
        if(n<=1){
            return 1;
        }
        int count=0;
        for(int i=1;i<=n;i++){
            count+=recursion(i-1)*recursion(n-i);
        }
        return count;
    }
    int numTrees(int n) {
        return recursion(n);
    }
};