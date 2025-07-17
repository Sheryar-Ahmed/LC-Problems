class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        int s, f;
        for(auto t: tokens){
            if(t == "+"){
                if(!st.empty()){
                s = st.top();
                st.pop();
                f= st.top();
                st.pop();
                st.push(f+s);
                }
            }else if(t == "-"){
                if(!st.empty()){
                s = st.top();
                st.pop();
                f= st.top();
                st.pop();
                st.push(f-s);
                }
            }else if(t == "*"){
                if(!st.empty()){
                s = st.top();
                st.pop();
                f= st.top();
                st.pop();
                st.push(f*s);
                }
            }else if(t == "/"){
                if(!st.empty()){
                s = st.top();
                st.pop();
                f= st.top();
                st.pop();
                st.push(f/s);
                }
            }else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};