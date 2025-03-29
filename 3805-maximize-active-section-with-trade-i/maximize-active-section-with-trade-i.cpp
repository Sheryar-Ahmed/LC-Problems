class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int re = 0,temp=0;
        for(char ch:s) re+=ch=='1';
        int n=s.size(),i=0;
        vector<int> v;
        while(i<n){
            int j=i+1;
            while(j<n && s[j]==s[i]) j++;
            if(s[i]=='0') v.push_back(j-i);
            i=j;
        }
        for(i=0;i+1<v.size();i++) temp=max(temp,v[i]+v[i+1]);
        return re+temp;
    }
};