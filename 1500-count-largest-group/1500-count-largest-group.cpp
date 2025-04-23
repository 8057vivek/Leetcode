class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> count(37,0);
        int maximum = 0;
        for(int i=1;i<=n;i++){
            int sum = 0;
            int num = i;
            while(num>0){
                int digit = num%10;
                num = num/10;
                sum+=digit;
            }
            count[sum]++;
            maximum = max(maximum, count[sum]);
        }

        int res = 0;
        for(int i=1;i<=36;i++){
            if(count[i]==maximum){
                res++;
            }
        }
        return res;
    }
};