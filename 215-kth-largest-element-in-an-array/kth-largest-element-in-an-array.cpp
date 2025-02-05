class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap; // Using minHeap instead of maxHeap
        for(auto c: nums){
            minHeap.push(c);
            if(minHeap.size() > k) { // Keep the heap size <= k
                minHeap.pop(); // Remove the smallest element if heap size exceeds k
            }
        }
        return minHeap.top();
    }
};