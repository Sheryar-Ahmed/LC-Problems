class Solution {
public:
    bool canFinish(vector<int>&piles, int k, int h){
        int hours = 0;
        // we have to check for that speed
        for(auto ban: piles){
            hours+=ceil(double(ban) / k );
            if(hours > h) return false;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1; // min speed;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;
        while(left <= right){
            int mid = left+ (right-left) / 2;
            
            if(canFinish(piles, mid, h)){
                result = mid;
                right = mid-1; // move to left to reduce speed;
            }else{
                left = mid+1; // if its slow then move futher
            }
        }
        return result;
    }
};