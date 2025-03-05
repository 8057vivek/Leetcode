class MinStack {
public:
    stack<int> st;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
        if(minStack.empty() || val<=minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {

        if(!st.empty()){
          if(st.top()==minStack.top()){
            minStack.pop();
          } 
          st.pop();
        }
        
    }
    
    int top() {
        if(!st.empty()){
            return st.top();
        }
        return -1;
    }
    
    int getMin() {
        if(!minStack.empty()){
            return minStack.top();
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */