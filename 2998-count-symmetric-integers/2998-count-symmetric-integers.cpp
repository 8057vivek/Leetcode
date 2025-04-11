class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i =low ;i<=high;i++){
            if(i<100){
                if(i%11==0){
                    count++;
                }
            }
            else if(i>=1000 && i<10000){
                int thousand_place = (i/1000)%10;
                int hundred_place = (i/100)%10;
                int tens_place = (i/10)%10;
                int ones_place = i%10;

                int firstHalf = thousand_place + hundred_place;
                int nextHalf = tens_place + ones_place;

                if(firstHalf==nextHalf){
                    count++;
                }
            }
        }
        return count;
    }
};