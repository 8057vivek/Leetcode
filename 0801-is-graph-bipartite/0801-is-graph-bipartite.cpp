class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& color, int currColor){
        color[node] = currColor;
        for(int& v: graph[node]){
            if(color[v]==color[node]){
                return false;
            }
            if(color[v]==-1){
                int colorV = 1 - color[node];
                if(!dfs(graph,v,color,colorV)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // 0 for green, 1 for red, it is also working as visited 
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(graph,i,color, 1)){
                    return false;
                }
            }
        }

        return true;
    }
};