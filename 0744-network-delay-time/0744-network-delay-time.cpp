class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int, int>>> map;
        for(auto & vec:times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            map[u].push_back({v,w});

        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> result(n+1, INT_MAX);

        result[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto & vec : map[node]){
                int adjNode = vec.first;
                int adjweight = vec.second;

                if(d+adjweight<result[adjNode]){
                    result[adjNode]=d+adjweight;
                    pq.push({d+adjweight,adjNode});
                }
            }
        }

        int ans = INT_MIN;
        for(int i= 1;i<=n;i++){
            if(result[i]>ans){
                ans=result[i];
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
        
    }
};