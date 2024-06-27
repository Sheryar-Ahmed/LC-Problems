class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> dCount;
        for(auto x: edges){
            dCount[x[0]]++;
            dCount[x[1]]++;
        }
        for(auto p: dCount){
            if(p.second == edges.size()){
                return p.first;
            }
        }
        return -1;
    }
};