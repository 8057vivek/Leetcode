class Solution {
public:
    bool bfs(int node, vector<vector<int>> & adj, vector<int> & color, int parentColor){
        queue<pair<int, int>> q;
        color[node] = parentColor;
        q.push({node, parentColor});

        while(!q.empty()){
            int currNode = q.front().first;
            int  currColor = q.front().second;
            q.pop();

            for(int nbr : adj[currNode]){
                if(color[nbr]==-1){
                    color[nbr]=1-currColor;
                    q.push({nbr, color[nbr]});
                }
                else if(color[nbr]==currColor){
                    return false;
                }
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);

        for(vector<int>& vec : dislikes){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1, -1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!bfs(i, adj, color, 1)){
                    return false;
                }
            }
        }
        return true;
    }
};