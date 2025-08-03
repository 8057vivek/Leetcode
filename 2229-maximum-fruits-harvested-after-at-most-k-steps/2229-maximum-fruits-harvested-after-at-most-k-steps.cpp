class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        // Step 1: Extract positions and build prefixSum
        vector<int> positions(n);
        vector<int> prefixSum(n + 1, 0);  // prefixSum[0] = 0

        for (int i = 0; i < n; ++i) {
            positions[i] = fruits[i][0];
            prefixSum[i + 1] = prefixSum[i] + fruits[i][1];
        }

        int maxFruits = 0;

        // Case 1: Go d steps left, then right
        for (int d = 0; d <= k / 2; ++d) {
            int i = startPos - d;
            int j = startPos + (k - 2 * d);

            int left = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            int right = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;

            if (left <= right) {
                int total = prefixSum[right + 1] - prefixSum[left];
                maxFruits = max(maxFruits, total);
            }
        }

        // Case 2: Go d steps right, then left
        for (int d = 0; d <= k / 2; ++d) {
            int i = startPos - (k - 2 * d);
            int j = startPos + d;

            int left = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            int right = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;

            if (left <= right) {
                int total = prefixSum[right + 1] - prefixSum[left];
                maxFruits = max(maxFruits, total);
            }
        }

        return maxFruits;
    }
};
