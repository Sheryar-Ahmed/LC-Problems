class Solution {
public:
    bool isPalindrome(string s) {
        // make the clean and to lower
        int n = s.size();
        if(n <= 1) return true;
        string clean = "";
        for(auto &c: s){
            if(isalnum(c)){
                clean+=tolower(c);
            }
        }
        cout<<clean<<endl;
        
        int l = 0;
        int r = clean.size()-1;
        while(l < r){
            if(clean[l] != clean[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};