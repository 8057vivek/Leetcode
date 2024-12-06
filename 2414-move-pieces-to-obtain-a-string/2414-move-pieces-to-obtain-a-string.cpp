class Solution {
public:
    bool canChange(string start, string target) {
        string filteredStart, filteredTarget;
    for (char c : start) {
        if (c != '_') filteredStart += c;
    }
    for (char c : target) {
        if (c != '_') filteredTarget += c;
    }
    if (filteredStart != filteredTarget) return false;

    // Validate the positions of 'L' and 'R'
    int i = 0, j = 0;
    int n = start.length();
    while (i < n && j < n) {
        // Find the next non-underscore character in start and target
        while (i < n && start[i] == '_') i++;
        while (j < n && target[j] == '_') j++;

        // If both indices are out of bounds, we're done
        if (i == n && j == n) break;

        // If one index is out of bounds, return false
        if (i == n || j == n) return false;

        // Check the rules for 'L' and 'R'
        if (start[i] != target[j]) return false;
        if (start[i] == 'L' && i < j) return false; // 'L' can only move left
        if (start[i] == 'R' && i > j) return false; // 'R' can only move right

        // Move to the next character
        i++;
        j++;
    }
    return true;
    }
};