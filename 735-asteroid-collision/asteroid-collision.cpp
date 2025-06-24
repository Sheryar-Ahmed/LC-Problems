class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int x : asteroids) {
            bool destroyed = false;

            while (!s.empty() && x < 0 && s.top() > 0) {
                if (s.top() < -x) {
                    s.pop(); // smaller right asteroid explodes
                } else if (s.top() == -x) {
                    s.pop(); // both explode
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // left asteroid explodes
                    break;
                }
            }

            if (!destroyed) s.push(x);
        }

        // Move stack to result vector
        vector<int> ans(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            ans[i] = s.top();
            s.pop();
        }

        return ans;
    }
};
