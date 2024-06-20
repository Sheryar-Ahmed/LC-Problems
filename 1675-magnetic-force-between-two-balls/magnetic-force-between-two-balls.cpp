#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPlaceBaskets(vector<int>& position, int m, int minDist) {
        int count = 1; // Place the first basket at the first position
        int lastPos = position[0];

        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minDist) {
                count++;
                lastPos = position[i];
                if (count == m) return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int left = 1; // Minimum possible distance
        int right = position.back() - position.front(); // Maximum possible distance
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceBaskets(position, m, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
