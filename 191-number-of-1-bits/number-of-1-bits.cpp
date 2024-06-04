class Solution {
public:
    int hammingWeight(int n) {
        int bit = 0;
        int res = 0;
        while(n != 0){
            int bit = (n & 1);
            if(bit == 1){
                res++;
            }
            n>>= 1;
        }
        return res;
    }
};