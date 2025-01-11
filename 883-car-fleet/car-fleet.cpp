class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, double>> cars; //position and time
        for(int i=0; i < n; i++){
            double time = static_cast<double>(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end());

        int result = 0;
        double maxTime = 0.0;

        for(int i=n-1; i >= 0; --i){
            double time = cars[i].second;
            if(time > maxTime){
                maxTime = time;
                result++;
            }
        }
        return result;
    }
};