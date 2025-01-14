class Solution {
public:
    int maxScore(string s) {
        int n = s.length();

        vector<int> Zero(n,0);
        vector<int> One(n,0);

        if(s[0]=='0'){
            Zero[0]=1;
        }
        if(s[n-1]=='1'){
            One[n-1]=1;
        }

        for(int i=1;i<n;i++){
            if(s[i]=='0'){
            Zero[i]=Zero[i-1]+1;
            }else{
                Zero[i]=Zero[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1'){
                One[i]=One[i+1]+1;
            }else{
                One[i]=One[i+1];
            }
        }
        int maximum = 0;

        for(int i=0;i<n-1;i++){
            int sum = One[i+1]+Zero[i];
            maximum=max(maximum,sum);
        }

        return maximum;
    }
};