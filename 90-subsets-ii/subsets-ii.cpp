#include <iostream>
#include <vector>
#include <algorithm>
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
     */
    void backtrack(vector<int>& state, vector<int>& choices, int start,
                   function<bool(vector<int>&)> isSolution,
                   function<bool(vector<int>&, int, int)> isValid,
                   function<void(vector<int>&)> process,
                   function<int(int)> getNext) {
        
        if (isSolution(state)) {
            process(state);
        }

        for (int i = start; i < choices.size(); i++) {
            // Skip duplicates to avoid duplicate subsets
            if (i > start && choices[i] == choices[i - 1]) continue;

            if (!isValid(state, choices[i], i)) continue;  // Skip invalid choices

            // Make a choice
            state.push_back(choices[i]);

            // Recursive call (getNext controls iteration logic)
            backtrack(state, choices, getNext(i), isSolution, isValid, process, getNext);

            // Undo the choice (backtrack)
            state.pop_back();
        }
    }

    vector<vector<int>> solve(vector<int>& choices,
                              function<bool(vector<int>&)> isSolution,
                              function<bool(vector<int>&, int, int)> isValid,
                              function<void(vector<int>&)> process,
                              function<int(int)> getNext) {
        vector<int> state;
        result.clear();  // Reset results for each problem
        sort(choices.begin(), choices.end());  // Sort to handle duplicates
        backtrack(state, choices, 0, isSolution, isValid, process, getNext);
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        BacktrackingSolver solver;

        // Define problem-specific logic using lambda functions
        auto isSolution = [](vector<int>& state) { return true; };  // All subsets are valid
        auto isValid = [](vector<int>& state, int choice, int index) { return true; };  // All choices are valid
        auto process = [&](vector<int>& state) { solver.result.push_back(state); };
        auto getNext = [](int i) { return i + 1; };  // Move to the next index (no reuse of elements)

        // Solve the problem
        return solver.solve(nums, isSolution, isValid, process, getNext);
    }
};