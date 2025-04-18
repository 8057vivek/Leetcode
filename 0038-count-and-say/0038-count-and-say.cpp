class Solution {
public:
    // string recursion(int n,int m,  string s){
    //     if(n>m){
    //         return "";
    //     }
    //     if(n==1){
    //         return "1";
    //     }
    //     string str = "";
        
    //     for(int i=1;i<s.length();i++){
    //         int count = 1;
    //         char c = s[i-1];
    //         while(s[i]==c){
    //             count++;
    //         }
    //         str = str+to_string(count)+'c';
    //     }
    //     recursion(n-1,m,str);
    //     return str;
    // }
    vector<pair<char,int>> StringToVector(string s){
        vector<pair<char, int>> vec;
        for(int i = 0; i < s.length();){
        int count = 1;
        char c = s[i];
        int j = i + 1;
        while(j < s.length() && s[j] == c){
            count++;
            j++;
        }
        vec.push_back({c, count});
        i = j;
    }
        return vec;
}

    string helper(vector<pair<char, int>>& vec){
        int n = vec.size();
        string s = "";
        for(int i=0;i<n;i++){
            s= s+ to_string(vec[i].second)+vec[i].first;
        }
        return s;
    }
    string countAndSay(int n) {
        unordered_map<int , string> mp;
        mp[1]="1";
        for(int i=2;i<=n;i++){
            vector<pair<char, int>> vec = StringToVector(mp[i-1]);
            string s = helper(vec);
            mp[i] = s;
        }

        return mp[n];
    }
};