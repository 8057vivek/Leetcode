class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> result;
        vector<int> indegree(n);

        if(n==1){
            return {0};
        }

        for(vector<int>& edge : edges){
            int  u = edge[0];
            int v = edge[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }

        while(n>2){
            int size = q.size();
            n-=size;
            while(size--){
                int node = q.front();
                q.pop();
                for(int nbr : adj[node]){
                    indegree[nbr]--;
                    if(indegree[nbr]==1){
                        q.push(nbr);
                    }
                }
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
        }
        

        return result;
    }
};