class Solution {
public:
    int countSeniors(vector<string>& details) {
    int count = 0;
    for (const string& detail : details) {
        // Extract the age from the string (characters at index 11 and 12)
        int age = stoi(detail.substr(11, 2));
        // Check if the age is greater than 60
        if (age > 60) {
            count++;
        }
    }
    return count;
    }
};