class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ageG = 0;
        for(auto x: details){
            int curr = stoi(x.substr(11, 2));
            if(curr > 60){
                ageG++;
            }
        }
        return ageG;
    }
};