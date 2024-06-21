class Solution {
public:
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int satisfiedCustomers = 0;

    // Calculate the number of satisfied customers when the owner is not grumpy
    for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0) {
            satisfiedCustomers += customers[i];
        }
    }

    // Calculate the additional customers that can be satisfied during the window
    int extraSatisfied = 0;
    int maxExtraSatisfied = 0;

    // Compute the sum of the first window
    for (int i = 0; i < minutes; ++i) {
        if (grumpy[i] == 1) {
            extraSatisfied += customers[i];
        }
    }
    maxExtraSatisfied = extraSatisfied;

    // Slide the window
    for (int i = minutes; i < n; ++i) {
        if (grumpy[i] == 1) {
            extraSatisfied += customers[i];
        }
        if (grumpy[i - minutes] == 1) {
            extraSatisfied -= customers[i - minutes];
        }
        maxExtraSatisfied = max(maxExtraSatisfied, extraSatisfied);
    }

    return satisfiedCustomers + maxExtraSatisfied;
}
};