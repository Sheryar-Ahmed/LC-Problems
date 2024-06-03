#include <string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;

        // Traverse both strings to find the longest prefix of t in s
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }

        // The number of characters to append is the remaining length of t
        return t.size() - j;
    }
};
