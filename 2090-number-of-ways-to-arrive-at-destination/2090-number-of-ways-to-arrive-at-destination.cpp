class Solution {
public:
    typedef pair<long long, int> P; // {time, neighbourNode} 
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<pair<int,int>>> adjList;
        for(vector<int>& vec : roads){
            adjList[vec[0]].push_back({vec[1],vec[2]});
            adjList[vec[1]].push_back({vec[0],vec[2]});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long > result(n, LLONG_MAX);
        vector<int> pathCount(n,0);

        result[0] = 0;
        pathCount[0] = 1;
        pq.push({0,0});

        while(!pq.empty()){
            long long currTime = pq.top().first;
            int currNode = pq.top().second;

            pq.pop();

            for(auto & vec : adjList[currNode]){
                int neighbour = vec .first;
                int time = vec.second;

                if(currTime+time<result[neighbour]){
                    result[neighbour]= currTime+time;
                    pq.push({result[neighbour],neighbour});
                    pathCount[neighbour] = pathCount[currNode];
                }else if(currTime + time == result[neighbour]){
                    pathCount[neighbour] = (pathCount[neighbour] + pathCount[currNode])%M;
                }
            }
        }

        return pathCount[n-1];
    }
};