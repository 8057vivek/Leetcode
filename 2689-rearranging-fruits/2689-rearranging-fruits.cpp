class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        map<int, int> combinedFreq;

        for (int x : basket1) {
            freq[x]++;
            combinedFreq[x]++;
        }
        for (int x : basket2) {
            freq[x]--;
            combinedFreq[x]++;
        }

        // ❗ Check total count of each fruit
        for (auto& [fruit, total] : combinedFreq) {
            if (total % 2 != 0) return -1; // impossible
        }

        vector<int> excess;
        int globalMin = INT_MAX;

        for (auto& [fruit, total] : combinedFreq) {
            globalMin = min(globalMin, fruit);
            int diff = freq[fruit];
            if (diff != 0) {
                for (int i = 0; i < abs(diff) / 2; ++i) {
                    excess.push_back(fruit);
                }
            }
        }

        sort(excess.begin(), excess.end());
        long long res = 0;
        int n = excess.size();
        for (int i = 0; i < n / 2; ++i) {
            res += min(excess[i], 2 * globalMin);
        }

        return res;
    }
};
