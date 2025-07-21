class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0;
        int o = 0;
        int t = 0;
        for(auto &x: nums){
            if( x == 0) z++;
            if( x == 1) o++;
            if(x == 2) t++;
        }
        int p = 0;
        while(z--){
            nums[p++] = 0;
        }
        while(o--){
            nums[p++] = 1;
        }
        while(t--){
            nums[p++] = 2;
        }
    }
};