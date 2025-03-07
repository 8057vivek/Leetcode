class Solution {
public:
    bool isPrime(int num){
        if(num<2){
            return false;
        }
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> vec;

        for(int i=left;i<=right;i++){
            if(isPrime(i)){
                if(!vec.empty() && i -vec.back()<=2){
                    return {vec.back(), i};
                }
                vec.push_back(i);
            }
        }
        if (vec.size() < 2) return {-1, -1};
        vector<int> result(2, -1);

        int minDiff = INT_MAX;
        int n = vec.size();
        for(int i=1;i<n;i++){
            int diff = vec[i]-vec[i-1];
            if(diff< minDiff){
                minDiff = diff;
                result[0] = vec[i-1];
                result[1] = vec[i];
            }
        }

        return result;
    }
};