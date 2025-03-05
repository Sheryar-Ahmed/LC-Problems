class Solution {
public:
    long long coloredCells(int n) {
//     1+0
// 5   (1+4*1)
// 13  (1+4*2)
// 25 (1+4*5)
// 33 (1+4*8)
// it makes a series
return 1+4LL*n*(n-1) / 2;
    }
};