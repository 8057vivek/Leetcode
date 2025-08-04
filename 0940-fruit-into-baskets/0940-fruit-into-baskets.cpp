class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n == 0) return 0;

        int type1 = -1, type2 = -1;
        int count1 = 0, count2 = 0;
        int left = 0, maxLen = 0;

        for (int right = 0; right < n; right++) {
            int curr = fruits[right];

            if (curr == type1 || type1 == -1) {
                type1 = curr;
                count1++;
            } else if (curr == type2 || type2 == -1) {
                type2 = curr;
                count2++;
            } else {
                while (count1 > 0 && count2 > 0) {
                    if (fruits[left] == type1) count1--;
                    else if (fruits[left] == type2) count2--;
                    left++;
                }

                // One of the counts is now 0 — we replace that type
                if (count1 == 0) {
                    type1 = curr;
                    count1 = 1;
                } else {
                    type2 = curr;
                    count2 = 1;
                }
                continue;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
