class Solution {
public:
    // count the letters frequency, sort in desceding order
    // for the first 8 we need to count the push as 1, for 2nd 8 2 push for 3 8
    // 3 and for 4 th push will be counted
    //  and each will be stored and at the end will be returned
    int minimumPushes(string& word) {
        int freq[26] = {0}; // Initialize frequency array
        for (char c : word) // Count frequencies of each character
            freq[c - 'a']++;
        sort(freq, freq + 26, greater<int>()); // Sort frequencies in descending order

        int sz = 0, push = 1, ans = 0; // Initialize variables
        for (; sz < 26 && freq[sz] != 0;
             sz++) { // Iterate through sorted frequencies
            if (sz >= 8 &&
                sz % 8 == 0) // Increment push count after every 8 characters
                push++;
            ans += freq[sz] * push; // Calculate total pushes
        }
        return ans; // Return total pushes
    }
};