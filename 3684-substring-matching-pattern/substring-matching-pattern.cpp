#include <string>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        // Extract prefix (p1) and suffix (p2) around '*'
        string p1 = p.substr(0, p.find('*'));
        string p2 = p.substr(p.find('*') + 1);

        // If p1 is empty, we check if s contains p2
        if (p1.empty()) {
            return s.find(p2) != string::npos;
        }
        // If p2 is empty, we check if s contains p1
        else if (p2.empty()) {
            return s.find(p1) != string::npos;
        }

        // Find the first occurrence of p1 and the last occurrence of p2 in s
        int index1 = s.find(p1);
        int index2 = s.rfind(p2);

        // Ensure both p1 and p2 exist and p2 appears after p1
        return index1 >= 0 && index2 >= 0 && index2 >= (index1 + p1.length());
    }
};
