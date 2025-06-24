class MyQueue {
private:
    stack<int> st;

public:
    MyQueue() {}

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }

        // Step 1: Pop all elements to reach the bottom
        int top = st.top();
        st.pop();

        // Step 2: Recursive call
        push(x);

        // Step 3: Push the element back (build the stack back up)
        st.push(top);
    }

    int pop() {
        int val = st.top();
        st.pop();
        return val;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};
