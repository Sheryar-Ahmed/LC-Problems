class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto x: nums){
            if(s.find(x) != s.end()){
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};