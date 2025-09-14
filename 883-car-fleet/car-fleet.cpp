class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // we need to calculate the time to reach destination.
        // formula i think its target - position[i] / speed[i];
        // we can sort positions by time.
        // 10-1, 8-1, 5-7, 3-3, 0-12
        int no_of_car_fleets = 0;
        vector<pair<int, double>>
            positionToTime; // position time to reach destination
        for (int i = 0; i < position.size(); i++) {
            double time = double(target - position[i]) / speed[i];
            positionToTime.push_back({position[i], time});
        }
        // sort by position in descending order.
        sort(positionToTime.begin(), positionToTime.end(),
             [](const auto& a, const auto& b) { return a.first > b.first; });
        double maxSoFar = 0.0;
        for (auto& [pos, time] : positionToTime) {
            if(time > maxSoFar){
                no_of_car_fleets++;
                maxSoFar = time;
            }
        }
        return no_of_car_fleets;
    }
};