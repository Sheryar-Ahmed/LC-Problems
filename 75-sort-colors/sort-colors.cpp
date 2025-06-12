class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0}; // count[0] = # of 0s, count[1] = # of 1s, count[2] = # of 2s

        for (int num : nums) {
            count[num]++;
        }

        int index = 0;
        for (int color = 0; color < 3; ++color) {
            for (int i = 0; i < count[color]; ++i) {
                nums[index++] = color;
            }
        }
    }
};
