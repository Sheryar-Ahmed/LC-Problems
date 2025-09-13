class MinStack {
private:
    stack<int> st;
    stack<int> minS;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minS.empty() || minS.top() >= val){
            minS.push(val);
        }
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        if(minS.empty()) return;
        if(top <= minS.top()){
            minS.pop();
        }
    }
    
    int top() {
        if(st.empty()) return 0;
        return st.top();
    }
    
    int getMin() {
        if(minS.empty()) return 0;
        return minS.top();
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