class Solution {
public:
    
    unordered_map<int,int> memo;
    int fib(int n) {
        if(memo.find(n)!=memo.end()){
            return memo[n];
        }
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int res = fib(n-1)+fib(n-2);
        memo[n]=res;

        return res;
    }
};