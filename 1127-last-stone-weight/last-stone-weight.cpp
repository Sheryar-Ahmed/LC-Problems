class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int first = maxHeap.top(); maxHeap.pop();
            int second = maxHeap.top(); maxHeap.pop();

            if (first != second) {
                maxHeap.push(first - second);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
