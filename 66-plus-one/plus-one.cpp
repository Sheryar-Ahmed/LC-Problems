class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1; // Initialize carry to 1 since we're adding one
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            ans.push_back(sum % 10); // Add the least significant digit to the answer
            carry = sum / 10; // Update carry for the next iteration
        }
        // If there is a carry after processing all digits, add it to the answer
        if (carry > 0) {
            ans.push_back(carry);
        }
        // Reverse the answer vector to get the correct order of digits
        reverse(ans.begin(), ans.end());
        return ans;
    }
};