class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n - 1; i++) {
            int complement = target - numbers[i];
            int L = i + 1, R = n - 1;
            while (L <= R) {
                int mid = L + (R - L) / 2;
                if (numbers[mid] == complement) {
                    return {i + 1, mid + 1}; // 1-based indexing
                } else if (numbers[mid] < complement) {
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
        }
        return {-1, -1}; // Shouldn't happen if one valid pair is guaranteed
    }
};
