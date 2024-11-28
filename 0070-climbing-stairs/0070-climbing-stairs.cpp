class Solution {
public:
    unordered_map<int, int> memo;
    int climbStairs(int n) {
        if(memo.find(n)!=memo.end()){
            return memo[n];
        }
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(n < 0){
            return 0;
        }

        int count = climbStairs(n-1)+climbStairs(n-2);

        memo[n]= count;

        return count;
    }
};