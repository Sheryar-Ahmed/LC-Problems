class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boat = 0;
        int L = 0;
        int R = people.size() - 1;
        while (L <= R) {
            // R will always go either with left or without it
            if(people[L]+people[R] <= limit){
                L++; // left will got with right
            }
            R--;
            boat++;
        }
        return boat;
    }
};