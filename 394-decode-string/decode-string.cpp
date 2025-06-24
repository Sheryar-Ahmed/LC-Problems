class Solution {
public:
    string decodeString(string s) {
        string stack;
        for (char c : s) {
            if (c != ']') {
                stack.push_back(c);
            } else {
                // Step 1: Get the string inside [...]
                string substr = "";
                while (!stack.empty() && stack.back() != '[') {
                    substr = stack.back() + substr;
                    stack.pop_back();
                }
                stack.pop_back(); // remove '['

                // Step 2: Get the repeat count (number before [)
                string k = "";
                while (!stack.empty() && isdigit(stack.back())) {
                    k = stack.back() + k;
                    stack.pop_back();
                }
                int repeat = stoi(k);

                // Step 3: Append the decoded string to stack
                while (repeat--) {
                    stack += substr;
                }
            }
        }
        return stack;
    }
};
