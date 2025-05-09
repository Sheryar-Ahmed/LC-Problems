class Solution {
public:
    int countSubstrings(string s) {
            int count=0;
            for(int i=0; i < s.size()-1; i++){
                middleout(s, i, i, count); //odd cases
                middleout(s, i, i+1, count); //even cases
            }
            return count+1;
    }

private:
    void middleout(const string& s, int i,int j, int & count){
        while( i >= 0 && j <= s.size()-1 && s[i] == s[j]){
            i--;
            j++;
            count++;
        }
    }
};