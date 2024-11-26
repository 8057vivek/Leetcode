class Solution {
public:
    
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in_degree(n, 0); // To store in-degrees of nodes

    // Calculate in-degree for each node
    for (const auto& edge : edges) {
        int from = edge[0], to = edge[1];
        in_degree[to]++;
    }

    int champion = -1; // Variable to store the potential champion
    int countZeroInDegree = 0; // Count nodes with in-degree 0

    // Identify nodes with in-degree 0
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            countZeroInDegree++;
            champion = i; // Update the potential champion
            if (countZeroInDegree > 1) return -1; // More than one node with in-degree 0
        }
    }

    return countZeroInDegree == 1 ? champion : -1;
    }
};