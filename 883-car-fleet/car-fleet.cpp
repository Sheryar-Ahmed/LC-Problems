class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; ++i) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort by position descending
        sort(cars.rbegin(), cars.rend());

        stack<double> st;
        for (auto& car : cars) {
            double time = car.second;
            if (st.empty() || time > st.top()) {
                st.push(time); // new fleet
            }
            // else it joins the previous fleet (do nothing)
        }

        return st.size();
    }
};
