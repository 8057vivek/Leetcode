class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

    // Step 2: Sort queries with original indices
    vector<pair<int, int>> queriesWithIndex;
    for (int i = 0; i < queries.size(); ++i) {
        queriesWithIndex.push_back({queries[i], i});
    }
    sort(queriesWithIndex.begin(), queriesWithIndex.end());

    // Step 3: Track max beauty for each query
    vector<int> result(queries.size());
    int maxBeauty = 0;
    int itemIndex = 0;

    for (const auto& [query, originalIndex] : queriesWithIndex) {
        // Move itemIndex until we exceed the current query price
        while (itemIndex < items.size() && items[itemIndex][0] <= query) {
            maxBeauty = max(maxBeauty, items[itemIndex][1]);
            ++itemIndex;
        }
        
        result[originalIndex] = maxBeauty;
    }

    return result;
    }
};