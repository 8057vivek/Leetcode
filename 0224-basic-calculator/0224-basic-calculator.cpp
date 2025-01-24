class Solution {
public:
    int evaluate(int index, string s) {
        long long ans = 0, num = 0, sign = 1; // sign = 1 for '+', -1 for '-'

        while (index < s.length()) {
            char ch = s[index];

            if (ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
            } else if (ch == '(') {
                num = evaluate(index + 1, s);
                int open = 1;
                index++;
                while (index < s.length()) {
                    if (s[index] == '(') open++;
                    else if (s[index] == ')') open--;
                    if (open == 0) break;
                    index++;
                }
            } else if (ch == ')') {
                return ans + sign * num;
            } else if (ch == '+' || ch == '-') {
                ans += sign * num;
                num = 0;
                sign = (ch == '+') ? 1 : -1;
            }

            index++;
        }

        return ans + sign * num;
    }

    int calculate(string s) {
        return evaluate(0, s);
    }
};
