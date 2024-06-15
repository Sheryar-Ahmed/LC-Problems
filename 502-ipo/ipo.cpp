#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Create a vector of pairs (capital, profit) and sort it based on capital
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());

        // Use a max-heap to keep track of the most profitable projects we can afford
        priority_queue<int> maxHeap;
        int i = 0;
        int n = projects.size();

        // Iterate at most k times to select projects
        while (k--) {
            // Add all the projects we can afford with our current capital to the heap
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }

            // If the heap is empty, we can't start any more projects
            if (maxHeap.empty()) {
                break;
            }

            // Select the most profitable project we can afford
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};
