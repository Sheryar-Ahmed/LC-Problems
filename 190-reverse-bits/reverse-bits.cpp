class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0; i < 32; i++){
            result <<= 1; //left shift
            result |= (n&1); //if it is 1 append it to the current place;
            n >>= 1; //right shift;
        }
        return result;
    }
};