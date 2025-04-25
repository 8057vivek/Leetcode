class Solution {
public:
    int dp[301][11];
    int recursion(vector<int>& jd, int n, int index, int days){
        /*Base Case :  only one day left you have to do all remaining jobs*/
        if(days==1){
            int maxD  = jd[index];
            for(int i=index;i<n;i++){
                maxD = max(maxD, jd[i]);
            }
            return maxD;
        }
        
        if(dp[index][days]!=-1){
            return dp[index][days];
        }

        int maxD = jd[index];
        int finalResult = INT_MAX;

        for(int i=index;i<=n-days;i++){
            maxD = max(maxD, jd[i]);
            int result = maxD + recursion(jd, n, i+1, days-1);
            finalResult = min(finalResult, result);
        }

        return dp[index][days] = finalResult;

    }
    int minDifficulty(vector<int>& jd, int d) { // jd = jobDifficulty
        int n = jd.size();
        if(n<d){
            return -1;
        }

        memset(dp, -1, sizeof(dp));

        return recursion(jd, n, 0, d); // starting with index = 0;

    }
};