class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        int maxOdd = 0;
        int minEven = 101; //max string length is 100
        for (auto it = freq.begin(); it != freq.end(); it++) {
            int count = it->second;
            if (count % 2 == 1) {
                if (count > maxOdd) {
                    maxOdd = count;
                }
            } else {
                if (count < minEven) {
                    minEven = count;
                }
            }
        }

        return maxOdd - minEven;

    }
};