class Solution {
public:
    void dfs(int node ,vector<vector<int>>& adj, vector<bool>& visited){
        visited[node]=true;
        for(int i=0;i<adj.size();i++){
            if(!visited[i] && adj[node][i]==1){
                dfs(i,adj,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,isConnected,visited);
                ans++;
            }
        }

        return ans;
    }
};