class Solution {
public:
    bool isConsecutiveAndSorted(const vector<int>& subarray) {
    for (int i = 1; i < subarray.size(); ++i) {
        if (subarray[i] != subarray[i - 1] + 1) {
            return false;
        }
    }
    return true;
}

    vector<int> resultsArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;

    for (int i = 0; i <= n - k; ++i) {
        vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
        if (isConsecutiveAndSorted(subarray)) {
            result.push_back(*max_element(subarray.begin(), subarray.end()));
        } else {
            result.push_back(-1);
        }
    }

    return result;
    }
};