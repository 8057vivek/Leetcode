class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stol(n);
        for(long long i=63;i>=1;i--) {
            long long low = 2;
            long long high = num-1;
            while(low<=high) {
                long long mid = low + (high-low)/2;
                long long val = 0;
                long long x = 1;
                for(long long j=1;j<=i;j++) {
                    val += x;
                    if(val>=num) break;
                    if(j<i && ((num-val)/x)<mid) {
                        val = 2e18;
                        break;
                    }
                    if(j<i) x *= mid;
                }
                if(val>num) high = mid-1;
                else if(val<num) low = mid+1;
                else return to_string(mid); 
            }
        }
        return "";
    }
};