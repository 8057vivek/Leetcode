class Solution {
public:
    int pivotInteger(int n) {
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0]=arr[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
        
        suffix[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+arr[i];
        }
        
        for(int i=0;i<n;i++){
            if(prefix[i]==suffix[i]){
                return i+1;
            }
        }
        
        return -1;
    }
};