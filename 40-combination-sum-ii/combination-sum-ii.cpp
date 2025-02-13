#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class BacktrackingSolver {
public:
    vector<vector<int>> result;  // Stores all valid solutions

    void backtrack(vector<int>& state, vector<int>& choices, int start,
                   function<bool(vector<int>&, int)> isSolution,
                   function<bool(vector<int>&, int, int)> isValid,
                   function<void(vector<int>&)> process,
                   function<int(int)> getNext,
                   int target) {
        
        if (isSolution(state, target)) {
            process(state);
            return;
        }

        for (int i = start; i < choices.size(); i++) {
            if (!isValid(state, choices[i], target)) continue;  // Skip invalid choices

            // Skip duplicate elements (to avoid duplicate sets in the result)
            if (i > start && choices[i] == choices[i - 1]) continue;

            // Make a choice
            state.push_back(choices[i]);

            // Recursive call (getNext controls iteration logic)
            backtrack(state, choices, getNext(i), isSolution, isValid, process, getNext, target - choices[i]);

            // Undo the choice (backtrack)
            state.pop_back();
        }
    }

    vector<vector<int>> solve(vector<int>& choices, int target,
                              function<bool(vector<int>&, int)> isSolution,
                              function<bool(vector<int>&, int, int)> isValid,
                              function<void(vector<int>&)> process,
                              function<int(int)> getNext) {
        vector<int> state;
        result.clear();  // Reset results for each problem
        backtrack(state, choices, 0, isSolution, isValid, process, getNext, target);
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates

        BacktrackingSolver solver;

        auto isSolution = [](vector<int>& state, int target) { return target == 0; };
        auto isValid = [](vector<int>& state, int choice, int target) { return target >= choice; };
        auto process = [&](vector<int>& state) { solver.result.push_back(state); };
        auto getNext = [](int i) { return i + 1; };  // Move to next index (each number used only once)

        return solver.solve(candidates, target, isSolution, isValid, process, getNext);
    }
};