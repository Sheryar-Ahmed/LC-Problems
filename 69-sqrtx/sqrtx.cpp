class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1){
            return x;
        }
        int left = 1;
        int right = x;

        while(left <= right){
            int mid = left+(right-left) / 2;
            int sqrt = x / mid;
            if(sqrt == mid){
                return mid;
            }else if(sqrt < mid){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return right;        
    }
};