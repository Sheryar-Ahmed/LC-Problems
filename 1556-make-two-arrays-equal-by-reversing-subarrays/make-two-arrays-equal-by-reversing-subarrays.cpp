class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> tarCnt(1001);
        vector<int> arrCnt(1001);
        for(auto &t: target){
            ++tarCnt[t];
        }
        for(auto &a: arr){
            ++arrCnt[a];
        }
        return tarCnt == arrCnt;
    }
};