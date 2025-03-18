class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int size = nums.size();
        if (size % 2 != 0) {
            return false;
        }

        // hashmap to check the count of each pair
        unordered_map<int, int> map;
        for (auto x : nums) {
            map[x]++;
        }

        for (auto& x : map) { // Iterate over key-value pairs
            if (x.second % 2 != 0) { // Check count (value) for odd frequency
                return false;
            }
        }
        return true;
    }
};