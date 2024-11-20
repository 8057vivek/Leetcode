class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.length();
        vector<int>freq(3,0);
        for(auto ch:s){
            freq[ch-'a']++;
        }
        if(freq[0]<k || freq[1]<k || freq[2]<k) return -1;

        int ans=0;
        int i=0;
        int j=0;
        while(i<n && j<n){
            freq[s[j]-'a']--;
            j++;
            while(freq[0]<k || freq[1]<k || freq[2]<k){
                freq[s[i]-'a']++;
                i++;
            }
            if(freq[0]>=k && freq[1]>=k && freq[2]>=k) ans=max(ans,j-i+1);
        }
        return n-ans+1;
    }
};