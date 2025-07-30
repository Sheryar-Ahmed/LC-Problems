class Solution {
public:
    bool isPossible(vector<int>& weights, int capacity, int days) {
        int current = 0;
        int usedDays = 1;

        for (int w : weights) {
            if (current + w > capacity) {
                usedDays++;
                current = 0;
            }
            current += w;
        }
        return usedDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = (low + high) / 2;
            if (isPossible(weights, mid, days)) {
                high = mid; // try smaller capacity
            } else {
                low = mid + 1; // need bigger capacity
            }
        }
        return low;
    }
};