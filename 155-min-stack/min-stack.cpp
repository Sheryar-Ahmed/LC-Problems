class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        ms.push(min((!ms.empty() ? ms.top() : val), val));
    }
    
    void pop() {
        st.pop();
        ms.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ms.top();
    }
private:
    stack<int> st;
    stack<int> ms;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */