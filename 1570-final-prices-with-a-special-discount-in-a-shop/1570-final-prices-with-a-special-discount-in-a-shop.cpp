class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> result(prices);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        // Check if we can apply a discount
        while (!st.empty() && prices[st.top()] >= prices[i]) {
            result[st.top()] -= prices[i];
            st.pop();
        }
        // Push the current index onto the stack
        st.push(i);
    }

    return result;  
    }
};