#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        // Traverse both strings from end to start
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0'; // Convert char to int
            if (j >= 0)
                sum += b[j--] - '0'; // Convert char to int

            result = to_string(sum % 2) + result; // Append remainder to result
            carry = sum / 2; // Update carry
        }

        // If there's still a carry left
        if (carry)
            result = '1' + result;

        return result;
    }
};
