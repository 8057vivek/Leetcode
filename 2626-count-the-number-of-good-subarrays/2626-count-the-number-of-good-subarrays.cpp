class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, pair<int, int>> mp;
        int l = 0;
        long long count = 0;
        long long total_pairs = 0;

        for (int r = 0; r < n; r++) {
            int num = nums[r];
            mp[num].first++;  // frequency

            if (mp[num].first == 2) {
                mp[num].second = 1;  // first pair
            } else if (mp[num].first > 2) {
                mp[num].second = mp[num].first - 1 + mp[num].second;
            }

            total_pairs += mp[num].first - 1;  // only the new pairs added

            // Shrink window from left until total_pairs < k
            while (total_pairs >= k) {
                // All subarrays from l to r to end are valid
                count += (n - r);

                int left_num = nums[l];
                total_pairs -= mp[left_num].first - 1;  // removing old pairs
                mp[left_num].first--;

                if (mp[left_num].first < 2) {
                    mp[left_num].second = 0;
                } else {
                    mp[left_num].second = mp[left_num].first * (mp[left_num].first - 1) / 2;
                }

                l++;
            }
        }

        return count;
    }
};
