class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int missing = 1;
        for(auto &x: nums){
            if( x > 0 && x == missing){
                missing++;
            }
        }
        return missing;
        // int n = nums.size();
        // vector<bool> seen(n, false);
        // for(auto &x: nums){
        //     if(x > 0 && x <= n){
        //         seen[x-1] = true;
        //     }
        // }
        // for(int i=0;i  < seen.size(); i++){
        //     if(!seen[i]) return i+1;
        // }
        // return n+1;
        // int missing = 1;
        // while(true){
        //     bool flag = true;
        //     for(auto x: nums){
        //         if(missing == x){
        //             flag = false;
        //         }
        //     }
        //     if(flag) return missing;
        //     missing++;
        // }
        // return missing;
    }
};