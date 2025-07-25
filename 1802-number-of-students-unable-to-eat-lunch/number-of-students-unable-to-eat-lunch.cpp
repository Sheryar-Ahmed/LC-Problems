class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0;
        
        for (int s : students) {
            if (s == 0) count0++;
            else count1++;
        }
        
        for (int s : sandwiches) {
            if (s == 0 && count0 > 0) {
                count0--;
            } else if (s == 1 && count1 > 0) {
                count1--;
            } else {
                // No one wants this sandwich
                break;
            }
        }
        
        return count0 + count1;
    }
};
