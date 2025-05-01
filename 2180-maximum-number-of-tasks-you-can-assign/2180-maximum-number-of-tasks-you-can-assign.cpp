class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> availableWorkers(workers.end() - k, workers.end());
        int remainingPills = pills;

        for (int i = k - 1; i >= 0; --i) {
            auto it = availableWorkers.lower_bound(tasks[i]);
            if (it != availableWorkers.end()) {
                availableWorkers.erase(it);
            } else {
                if (remainingPills == 0) return false;
                it = availableWorkers.lower_bound(tasks[i] - strength);
                if (it == availableWorkers.end()) return false;
                availableWorkers.erase(it);
                remainingPills--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min(tasks.size(), workers.size()), result = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};
