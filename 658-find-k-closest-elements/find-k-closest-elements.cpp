class Solution {
public:
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    
    // Find the first index where arr[i] >= x
    int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    
    int left = pos - 1;
    int right = pos;

    // Pick k closest numbers
    vector<int> result;
    while (k--) {
        if (left < 0) {                 // must take from right
            result.push_back(arr[right++]);
        } else if (right >= n) {        // must take from left
            result.push_back(arr[left--]);
        } else {
            // Compare distances to x
            if (x - arr[left] <= arr[right] - x)
                result.push_back(arr[left--]);
            else
                result.push_back(arr[right++]);
        }
    }

    // We collected them in unsorted order, so sort
    sort(result.begin(), result.end());
    return result;
}

};