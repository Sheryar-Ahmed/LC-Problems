class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0L);
        if (sum % 4 != 0) return false;
        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend()); // largest first
        vector<int> sides(4, 0);

        return backtrack(0, matchsticks, sides, target);
    }

    bool backtrack(int idx, vector<int>& matchsticks, vector<int>& sides, int target) {
        if (idx == matchsticks.size())
            return sides[0] == target && sides[1] == target &&
                   sides[2] == target && sides[3] == target;

        int val = matchsticks[idx];
        for (int i = 0; i < 4; i++) {
            if (sides[i] + val > target) continue; // prune if overflow

            sides[i] += val; // choose
            if (backtrack(idx + 1, matchsticks, sides, target))
                return true;
            sides[i] -= val; // undo

            if (sides[i] == 0) break; // symmetry pruning
        }
        return false;
    }
};
