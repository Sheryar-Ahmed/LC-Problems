class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0); // location max = 1000
        
        for (auto& t : trips) {
            diff[t[1]] += t[0]; // pickup
            diff[t[2]] -= t[0]; // drop-off
        }
        
        int curr = 0;
        for (int i = 0; i <= 1000; i++) {
            curr += diff[i];
            if (curr > capacity) return false;
        }
        
        return true;
    }
};
