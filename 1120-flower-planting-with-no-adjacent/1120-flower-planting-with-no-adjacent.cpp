class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& flower, vector<int>& result,vector<int>& types){
        vector<bool> used(5,false);


        for(int nbr : adj[node]){
            if(flower[nbr]!=-1){
                used[flower[nbr]]=true;
            }
        }

        for(int f : types){
            if(!used[f]){
                result[node] = f;
                flower[node] = f;
                break;
            }
        }

        for(int nbr : adj[node]){
            if(flower[nbr]==-1){
                dfs(nbr,adj,flower,result,types);
            }
        }

    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(vector<int>& vec : paths){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n+1);
        vector<int> flower(n+1, -1);
        vector<int> types = {1,2,3,4};

        for(int i=1;i<n+1;i++){
            if(flower[i]==-1){
                dfs(i,adj, flower, result,types);
            }
        }

        result.erase(result.begin());
        return result;
    }
};