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
     * @param start      - Index to start iteration (useful for combinations)
     * @param isSolution - Lambda function to check if state is a solution
     * @param isValid    - Lambda function to validate choices
     * @param process    - Lambda function to process valid solutions
     * @param getNext    - Lambda function to get the next index (permutations/combinations)
     * @param target     - Target value for Combination Sum
     */
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        BacktrackingSolver solver;

        auto isSolution = [](vector<int>& state, int target) { return target == 0; };
        auto isValid = [](vector<int>& state, int choice, int target) { return target >= choice; };
        auto process = [&](vector<int>& state) { solver.result.push_back(state); };
        auto getNext = [](int i) { return i; };  // Stay at the same index (allows reuse of elements)

        return solver.solve(candidates, target, isSolution, isValid, process, getNext);
    }
};