class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto x: nums){
            sum+=x;
        }

        if(sum % k == 0) {
            return 0;
        }else if( sum  < k){
            return sum;
        }else if( sum > k ){
            return sum % k;
        }
        return -1;
    }
};