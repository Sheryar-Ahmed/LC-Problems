class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size()-1;
        while(size--) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
       int val = q.front();
       q.pop();
       return val;
    }
    
    int top() {
       return q.front();
    }
    
    bool empty() {
        return !!q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */