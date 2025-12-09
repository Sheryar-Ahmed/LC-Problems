class Solution {
public:
    long long solveMinMax(long long lo, long long hi,
                          function<bool(long long)> can) {
        long long ans = hi;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        long long lo = 1; // speed cannot be 0
        long long hi = *max_element(piles.begin(), piles.end());

        return solveMinMax(lo, hi, [&](long long speed) {
            long long hours = 0;

            for (long long p : piles) {
                // time = ceil(p / speed)
                hours += (p + speed - 1) / speed;

                if (hours > h) return false; // prune early
            }

            return hours <= h;
        });
    }
};
