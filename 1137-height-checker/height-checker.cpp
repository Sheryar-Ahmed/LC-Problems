class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights.begin(), heights.end());
        sort(heights.begin(), heights.end());
        int indices = 0;
        for(int i=0; i < heights.size(); i++){
            if(expected[i] != heights[i]){
                indices++;
            }
        }
        return indices;
    }
};