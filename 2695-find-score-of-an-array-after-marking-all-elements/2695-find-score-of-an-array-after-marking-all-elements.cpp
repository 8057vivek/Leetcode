class Solution {
public:
    long long findScore(vector<int>& nums) {
    int n = nums.size();
    vector<bool> marked(n, false); 
    long long score = 0;

    // Min-heap to store (value, index)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    // Push all elements into the heap
    for (int i = 0; i < n; ++i) {
        minHeap.push({nums[i], i});
    }

    // Process the heap
    while (!minHeap.empty()) {
        auto [value, idx] = minHeap.top();
        minHeap.pop();

        // Skip if already marked
        if (marked[idx]) continue;

        // Add the value to the score
        score += value;

        // Mark the current element and its neighbors
        marked[idx] = true;
        if (idx > 0) marked[idx - 1] = true;  // Mark left neighbor
        if (idx < n - 1) marked[idx + 1] = true;  // Mark right neighbor
    }

    return score;
    }
};