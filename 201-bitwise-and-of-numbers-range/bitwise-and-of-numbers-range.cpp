class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left){
            right = (right & (right-1)); //everytime we get a smaller number as it reduces the set bits to zero.
        }
        return right;
    }
};