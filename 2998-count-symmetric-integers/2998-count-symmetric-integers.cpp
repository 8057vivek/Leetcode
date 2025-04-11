class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low;i<=high;i++){
            string str = to_string(i);
            int l = str.length();
            if(l%2==0){
                int firstHalfSum = 0;
                for(int j=0;j<l/2;j++){
                    firstHalfSum+=str[j]-'0';
                }
                int nextHalfSum = 0;
                for(int k=l/2;k<l;k++){
                    nextHalfSum+=str[k]-'0';
                }
                if(firstHalfSum==nextHalfSum){
                    count++;
                }
            }
        }
        return count;
    }
};