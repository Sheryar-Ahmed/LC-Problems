#include <algorithm>
class Solution {
public:
    bool findSuccessor(vector<int>& nums, int i, int k, int n){
        int next = nums[i]+1; //next element
        nums[i] = -1; //mark as visited;
        int count = 1;
        i+=1;
        while(i < n && count < k){
            if(next == nums[i]){
                next = nums[i]+1;
                nums[i] = -1;
                count++;
            }
            i++;
        }
        return count == k;
    }
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        sort(nums.begin(), nums.end());
        for(int i=0; i < n; i++){
            if(nums[i] >= 0){
                if(!findSuccessor(nums, i, k, n)) return false;
            }
        }
        return true;
    }
};