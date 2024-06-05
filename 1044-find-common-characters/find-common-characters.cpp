#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Step 1: Initialize the frequency array with the first word
        vector<int> charCount(26, 0);
        for (char c : words[0]) {
            charCount[c - 'a']++;
        }

        // Step 2: Update the frequency array with each subsequent word
        for (int i = 1; i < words.size(); i++) {
            vector<int> currentCount(26, 0);
            for (char c : words[i]) {
                currentCount[c - 'a']++;
            }

            // Update the reference frequency array to the minimum frequency found
            for (int j = 0; j < 26; j++) {
                charCount[j] = min(charCount[j], currentCount[j]);
            }
        }

        // Step 3: Construct the result vector
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (charCount[i] > 0) {
                result.push_back(string(1, 'a' + i));
                charCount[i]--;
            }
        }

        return result;
    }
};
