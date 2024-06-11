#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;
        vector<int> left;

        // Count frequency of each number in arr1 and separate out the elements not in arr2
        for(auto x: arr1){
            if(find(arr2.begin(), arr2.end(), x) == arr2.end()){
                left.push_back(x);
            }
            freq[x]++;
        }

        vector<int> ans;

        // Add elements in the order they appear in arr2
        for(auto x: arr2){
            if(freq.find(x) != freq.end()){
                for(int i = 0; i < freq[x]; i++){
                    ans.push_back(x);
                }
                freq.erase(x); // Remove the element after adding
            }
        }

        // Add the remaining elements (not in arr2) and sort them
        sort(left.begin(), left.end());
        for(auto x: left){
            ans.push_back(x);
        }

        return ans;
    }
};
