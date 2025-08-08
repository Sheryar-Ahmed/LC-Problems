#include <string>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";
        
        while (!pq.empty()) {
            auto [count1, char1] = pq.top(); pq.pop();
            
            int len = result.size();
            // If last two characters are the same as char1, pick next letter
            if (len >= 2 && result[len - 1] == char1 && result[len - 2] == char1) {
                if (pq.empty()) break; // No other letter to use → stop
                auto [count2, char2] = pq.top(); pq.pop();
                
                result.push_back(char2);
                count2--;
                if (count2 > 0) pq.push({count2, char2});
                
                pq.push({count1, char1}); // Put back char1 for later
            } 
            else {
                // We can safely use char1 (once or twice, but no more than needed)
                int useCount = min(2, count1); 
                if (len >= 1 && result[len - 1] == char1) useCount = 1; // avoid triple
                for (int i = 0; i < useCount; i++) {
                    result.push_back(char1);
                }
                count1 -= useCount;
                if (count1 > 0) pq.push({count1, char1});
            }
        }
        
        return result;
    }
};
