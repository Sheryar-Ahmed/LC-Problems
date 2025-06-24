class FreqStack {
private:
    unordered_map<int, int> freq;
    priority_queue<tuple<int, int, int>> pq; // (freq, timestamp, val)
    int time = 0;

public:
    FreqStack() {}

    void push(int val) {
        freq[val]++;
        pq.push({freq[val], time++, val});
    }

    int pop() {
        auto [f, t, val] = pq.top(); pq.pop();
        freq[val]--;
        return val;
    }
};
