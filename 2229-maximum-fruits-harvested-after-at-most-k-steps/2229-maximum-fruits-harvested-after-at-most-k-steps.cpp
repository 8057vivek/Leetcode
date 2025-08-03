class Solution {
public:
    bool canReach(int left, int right, int start, int k) {
        int goLeftFirst = abs(start - left) + (right - left);
        int goRightFirst = abs(start - right) + (right - left);
        return min(goLeftFirst, goRightFirst) <= k;
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        // vector<int> positions(n);
        // for(int i=0;i<n;i++){
        //     positions[i] = fruits[i][0];
        // }

        // int lowerBound = lower_bound(positions.begin(),positions.end(),startPos-k)-positions.begin();
        // int upperBound = upper_bound(positions.begin(),positions.end(),startPos+k)-positions.begin()-1;

        int l = 0;
        int sum = 0;
        int maxFruits = 0;

        for (int r = 0; r < n; ++r) {
            sum += fruits[r][1];

            // Shrink window if not reachable within k steps
            while (l <= r && !canReach(fruits[l][0], fruits[r][0], startPos, k)) {
                sum -= fruits[l][1];
                l++;
            }

            // Update max fruits if valid window
            maxFruits = max(maxFruits, sum);
        }

        return maxFruits;
    }
};