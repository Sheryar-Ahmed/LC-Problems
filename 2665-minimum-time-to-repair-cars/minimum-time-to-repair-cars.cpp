class Solution {
public:
    bool canRepairAllCars(vector<int>& ranks, long long T, int cars) {
        long long totalCars = 0;
        for (int r : ranks) {
            totalCars += sqrt(T / r);  // Maximum cars this mechanic can repair in T minutes
            if (totalCars >= cars) return true;  // Early exit
        }
        return totalCars >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;  // Min possible time
        long long right = (long long) *min_element(ranks.begin(), ranks.end()) * (long long) cars * cars;
        long long answer = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairAllCars(ranks, mid, cars)) {
                answer = mid;
                right = mid - 1;  // Try to minimize time
            } else {
                left = mid + 1;  // Increase time
            }
        }
        return answer;
    }
};