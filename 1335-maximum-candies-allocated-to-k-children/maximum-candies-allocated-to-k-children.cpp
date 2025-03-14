class Solution {
public:
    bool canGiveC(vector<int>& candies, int mid, long long k) {
        if (mid == 0) return false; // Avoid division by zero

        long long count = 0;
        for (int c : candies) {
            count += (c / mid);
            if (count >= k) return true; // No need to check further
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = *max_element(candies.begin(), candies.end()), result = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (canGiveC(candies, mid, k)) {
                result = mid;  // Possible answer, try higher values
                left = mid + 1; // Increase to find max possible
            } else {
                right = mid - 1; // Decrease to check for a smaller valid number
            }
        }
        return result;
    }
};
