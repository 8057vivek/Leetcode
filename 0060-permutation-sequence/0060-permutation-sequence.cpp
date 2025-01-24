class Solution {
public:
    long long factorial(int n){
        if(n<=1){
            return 1;
        }

        return n*factorial(n-1);   
    }
    string getPermutation(int n, int k) {
        set<int> st;
        for(int i=1;i<=n;i++){
            st.insert(i);
        }
        string ans="";
        for(int i=0;i<n;i++){
            for(int it : st){
                int fact = factorial(n-i-1);
                if(k>fact){
                    k-=fact;
                }else{
                    ans.push_back(it+'0');
                    st.erase(it);
                    break;
                }
            }
        }
        return ans;
    }
};