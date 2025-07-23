class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = s.size()-1;
        while(L < R){
            while(!isalnum(s[L]) && L < R){
                L++;
            }
            while(!isalnum(s[R]) && R > L){
                R--;
            }
            
            if(tolower(s[L]) != tolower(s[R])){
                return false;
            }
            L++;
            R--;
        }
        return true;
    }
};