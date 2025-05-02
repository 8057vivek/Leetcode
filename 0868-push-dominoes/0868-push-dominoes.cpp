class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.size();
        vector<int> forces(n);
        int force = 0;

        // left to right
        for(int i=0;i<n;i++){
            if(dom[i]=='R') force = n;
            else if(dom[i]=='L') force =0;
            else force = max(force-1,0);
            forces[i] = force;
        }
        // right to left
        for(int i=n-1;i>=0;i--){
            if(dom[i]=='L') force = n;
            else if(dom[i]=='R') force =0;
            else force = max(force-1,0);
            forces[i] -= force;
        }

        string res = "";
        for(int num : forces){
            if(num>0) res+='R';
            else if(num<0) res+='L';
            else res+='.';
        }

        return res;
    }
};