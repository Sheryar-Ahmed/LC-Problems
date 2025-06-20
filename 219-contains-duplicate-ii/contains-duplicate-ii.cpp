class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        set<int> window;
        for(int r = 0; r < nums.size(); r++){
            // we have to set the window
            if(r-l > k){
                window.erase(nums[l]);
                l++;
            }
            if(window.find(nums[r]) != window.end()){ // we found a duplicate in the window
                return true;
            }
            window.insert(nums[r]);
        }
        return false;

    }
};