class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) return stoi(tokens[0]);  
        stack<int> st;
        int result = 0;
        for (int i = 0; i < tokens.size(); i++) {
            int a, b;
            if (tokens[i] == "*") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b * a);
                result = b*a;

            } else if (tokens[i] == "/") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b / a);
                result = static_cast<int>(b/a);

            } else if (tokens[i] == "+") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b+a);
                result = b+a;

            } else if (tokens[i] == "-") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b - a);
                result = b - a;
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return result;
    }
};