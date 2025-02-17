#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class BacktrackingSolver {
public:
    vector<vector<int>> result;  // Stores all valid solutions

    /**
     * Generalized Backtracking Function
     * 
     * @param state      - Current partial solution
     * @param choices    - Available choices for selection
     * @param start      - Not used for permutations, needed for combinations
     * @param used       - Tracks which elements are already used (needed for permutations)
     * @param isSolution - Lambda function to check if state is a solution
     * @param isValid    - Lambda function to validate choices (not used for permutations)
     * @param process    - Lambda function to process valid solutions
     * @param getNext    - Not used for permutations, needed for combinations
     */
    void backtrack(vector<int>& state, vector<int>& choices, int start, vector<bool>& used,
                   function<bool(vector<int>&)> isSolution,
                   function<void(vector<int>&)> process) {
        
        if (isSolution(state)) {
            process(state);
            return;
        }

        for (int i = 0; i < choices.size(); i++) {
            if (used[i]) continue;  // Skip already used elements

            // Make a choice
            used[i] = true;
            state.push_back(choices[i]);

            // Recursive call
            backtrack(state, choices, start, used, isSolution, process);

            // Undo the choice (backtrack)
            used[i] = false;
            state.pop_back();
        }
    }

    vector<vector<int>> solve(vector<int>& choices,
                              function<bool(vector<int>&)> isSolution,
                              function<void(vector<int>&)> process) {
        vector<int> state;
        vector<bool> used(choices.size(), false);  // Track used elements
        result.clear();
        backtrack(state, choices, 0, used, isSolution, process);
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        BacktrackingSolver solver;

        auto isSolution = [&](vector<int>& state) { return state.size() == nums.size(); };
        auto process = [&](vector<int>& state) { solver.result.push_back(state); };

        return solver.solve(nums, isSolution, process);
    }
};
