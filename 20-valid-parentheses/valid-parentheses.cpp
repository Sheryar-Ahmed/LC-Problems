class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2) return false;
        stack<char> st;
        int n = 0;

        while (n < s.size()) {
            if (s[n] == '(' || s[n] == '{' || s[n] == '[') {
                st.push(s[n]);
            } else {
                if (st.empty()) return false; // check first!
                if ((s[n] == ')' && st.top() == '(') ||
                    (s[n] == '}' && st.top() == '{') ||
                    (s[n] == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false; // mismatch case
                }
            }
            n++;
        }
        return st.empty();
    }
};
