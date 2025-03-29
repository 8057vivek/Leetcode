class Solution {
public:
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int Q = queries.size();
        vector<int> result(Q,0);

        vector<pair<int, int>> sortedQueries;
        for(int i=0;i<Q;i++){
            sortedQueries.push_back({queries[i],i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int points = 0;
        pq.push({grid[0][0],0,0}); // {val, row, col}
        visited[0][0] = true;

       for(int i=0;i<Q;i++){
            int queryValue = sortedQueries[i].first;
            int index = sortedQueries[i].second;

            while(!pq.empty() && pq.top()[0]<queryValue){
                int i  = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();
                points++;

                for(auto& dir : directions){
                    int i_ = i+dir[0];
                    int j_ = j+dir[1];
                    if(i_>=0 && i_<m && j_<n && j_>=0 && !visited[i_][j_]){
                        pq.push({grid[i_][j_],i_,j_});
                        visited[i_][j_] = true;
                    }

                }
            }
            result[index] +=points;
       }

        return result;
    }
};