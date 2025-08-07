class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> maxH;
        for (auto& [c, f] : freq) {
            maxH.push({f, c});
        }

        string ans = "";

        while (maxH.size() > 1) {
            auto [freq1, char1] = maxH.top(); maxH.pop();
            auto [freq2, char2] = maxH.top(); maxH.pop();

            // Append both characters (they are different)
            ans += char1;
            ans += char2;

            // Decrease and push back if there's more left
            if (--freq1 > 0) maxH.push({freq1, char1});
            if (--freq2 > 0) maxH.push({freq2, char2});
        }

        // Check if one character remains
        if (!maxH.empty()) {
            auto [f, c] = maxH.top();
            if (f > 1) return "";  // Cannot place same char twice
            ans += c;
        }

        return ans;
    }
};
