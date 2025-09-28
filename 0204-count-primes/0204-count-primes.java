class Solution {
    public int countPrimes(int n) {
        if(n<2){
            return 0;
        }
        int count = 0;
        boolean[] arr = new boolean[n];
        for(int i=0;i<n;i++){
            arr[i] = true;
        }

        for(int i=2;i*i<n;i++){
            for(int j=i*i;j<n;j+=i){
                if(j%i==0){
                    arr[j]=false;
                }
            }
        }

        for(boolean b : arr){
            if(b==true){
                count++;
            }
        }

        return count-2;
    }
}