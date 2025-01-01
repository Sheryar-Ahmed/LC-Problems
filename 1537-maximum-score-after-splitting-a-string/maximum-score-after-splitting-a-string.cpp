class Solution {
public:
    int maxScore(string s) {
        int totalNo1s = 0;
        int leftNo1s =0;
        int leftNo0s = 0;
        int maxS = INT_MIN;
        for(auto c: s){
            if(c == '1') totalNo1s++;
        }
        for(size_t i=0; i < s.size()-1; i++){
            if(s[i] == '0') leftNo0s++;
            else leftNo1s++;
            int rightNo1s = totalNo1s - leftNo1s;
            maxS = max(maxS, leftNo0s+rightNo1s);
        }
        return maxS;
    }
};