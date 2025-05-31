class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); 

        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            diff[l] += 1;
            if (r + 1 < n) {
                diff[r + 1] -= 1;
            }
        }

        int applied = 0;
        for (int i = 0; i < n; ++i) {
            applied += diff[i];
            if (applied < nums[i]) {
                return false; 
            }
        }

        return true;
    }
};
