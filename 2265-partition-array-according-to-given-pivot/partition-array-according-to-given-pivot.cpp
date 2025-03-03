class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> larger;
        int equal_count = 0;
        vector<int> res;
        for(auto &n: nums){
            if(n < pivot){
                smaller.push_back(n);
            } else if(n > pivot){
                larger.push_back(n);
            }else {
                equal_count++;
            }
        }
        
        for(auto x: smaller){
            res.push_back(x);
        }

        for(int i=1; i <= equal_count; i++){
            res.push_back(pivot);
        }

        for(auto x: larger){
            res.push_back(x);
        }

        return res;
    }
};