class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.size();
        string res(n, '.');
        int i = 0;

        // Handle initial left push if present
        while (i < n && dom[i] == '.') i++;
        if (i < n && dom[i] == 'L') {
            for (int k = 0; k < i; ++k) res[k] = 'L';
        }

        int prev = -1;
        while (i < n) {
            if (dom[i] != '.') {
                char left = dom[prev >= 0 ? prev : i];
                char right = dom[i];
                if (prev != -1) {
                    if (left == 'R' && right == 'L') {
                        int l = prev + 1, r = i - 1;
                        while (l < r) {
                            res[l++] = 'R';
                            res[r--] = 'L';
                        }
                    } else if (left == 'R' && right == 'R') {
                        for (int k = prev + 1; k < i; ++k) res[k] = 'R';
                    } else if (left == 'L' && right == 'L') {
                        for (int k = prev + 1; k < i; ++k) res[k] = 'L';
                    }
                }
                res[i] = right;
                prev = i;
            }
            ++i;
        }

        // Handle trailing right push
        if (prev != -1 && dom[prev] == 'R') {
            for (int k = prev + 1; k < n; ++k) res[k] = 'R';
        }

        return res;
    }
};
