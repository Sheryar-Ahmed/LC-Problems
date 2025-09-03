class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniq;
        for(auto &x: nums){
            if(uniq.find(x) != uniq.end()){
                return true;
            }
            uniq.insert(x);
        }
        return false;
    }
};