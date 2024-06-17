class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0) return false; // Negative numbers don't have real square roots
        long i = 0;
        long j = static_cast<long>(sqrt(c)); // sqrt of c is the maximum value j can have
        while (i <= j) {
            long sum = i * i + j * j;
            if (sum == c) {
                return true;
            }
            if (sum < c) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};
