class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &c: s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if( (top == '(' && c != ')') || 
                (top == '{' && c != '}') || 
                (top == '[' && c != ']')){
                    return false;
                }
            }
        }
        return st.empty() ? true : false;
    }
};