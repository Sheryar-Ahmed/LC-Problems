#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        unordered_map<int, string> map = {
            {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
            {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
            {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
            {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
            {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},
            {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}
        };

        vector<int> groupNo = {1000000000, 1000000, 1000, 1};
        vector<string> groupName = {"Billion", "Million", "Thousand", ""};

        string ans;
        for (int i = 0; i < groupNo.size(); ++i) {
            if (num >= groupNo[i]) {
                ans += createChunk(num / groupNo[i]) + (groupName[i].empty() ? "" : " " + groupName[i]) + " ";
                num %= groupNo[i];
            }
        }

        // Trim any trailing spaces
        while (!ans.empty() && isspace(ans.back())) {
            ans.pop_back();
        }

        return ans;
    }

private:
    string createChunk(int num) {
        unordered_map<int, string> map = {
            {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
            {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
            {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
            {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
            {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},
            {100, "Hundred"}
        };

        string res;
        if (num >= 100) {
            res += map[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            res += map[(num / 10) * 10] + " ";
            num %= 10;
        }
        if (num > 0) {
            res += map[num] + " ";
        }

        // Trim any trailing spaces
        while (!res.empty() && isspace(res.back())) {
            res.pop_back();
        }

        return res;
    }
};

// Example usage:
// int main() {
//     Solution solution;
//     cout << solution.numberToWords(123) << endl;       // Output: "One Hundred Twenty Three"
//     cout << solution.numberToWords(12345) << endl;     // Output: "Twelve Thousand Three Hundred Forty Five"
//     cout << solution.numberToWords(1234567) << endl;   // Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
//     return 0;
// }
