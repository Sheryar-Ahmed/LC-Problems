class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int res = 0;
        for(auto &s: operations){
            if(s == "+"){
                int first = st.top();st.pop();
                int second = st.top();
                st.push(first);
                int sum = first+second;
                st.push(sum);
                res+=sum;
            }else if(s == "D"){
                int top = st.top();
                int d = top*2;
                st.push(d);
                res+=d;
            }else if( s== "C"){
                int inv = st.top(); st.pop();
                res-=inv;
            }else{
                int x = stoi(s);
                st.push(x);
                res+=x;
            }
        }
    return res;
    }
};