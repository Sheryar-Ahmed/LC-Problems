class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the people weights in ascending order
        sort(people.begin(), people.end());

        int i = 0;
        int j = people.size() - 1;
        int count = 0;

        while (i <= j) {
            int sum = people[i] + people[j];

            // If the lightest and heaviest person can share a boat
            if (sum <= limit) {
                i++; // include lighter person
                j--; // include heavier person
            } else {
                // Only the heavier person can go (they're too heavy to pair)
                j--;
            }

            // In either case, we used a boat
            count++;
        }

        return count;
    }
};
