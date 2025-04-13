class Solution {
public:
    
    const int M = 1e9+7;
    long long Expo(long long a, long long b){ //a^b
        if(b==0){
            return 1;
        }
        long long half = Expo(a,b/2);
        long long result = (half * half)%M;
        if(b%2==1){
            result = (result*a)%M;
        }
        return result;
    }

    long long countGoodNumbers(long long n) {
        long long even = Expo(5,(n+1)/2);
        long long odd = Expo(4,n/2);

        return (even * odd)%M;
    }
};