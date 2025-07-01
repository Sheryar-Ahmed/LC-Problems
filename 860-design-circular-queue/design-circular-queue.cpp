class MyCircularQueue {
private:
    vector<int> queue;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
    }

    bool enQueue(int value) {
        if (queue.size() == capacity) {
            return false;
        }
        queue.push_back(value);
        return true;
    }

    bool deQueue() {
        if (queue.empty()) {
            return false;
        }
        queue.erase(queue.begin());
        return true;
    }

    int Front() {
        return queue.empty() ? -1 : queue.front();
    }

    int Rear() {
        return queue.empty() ? -1 : queue.back();
    }

    bool isEmpty() {
        return queue.empty();
    }

    bool isFull() {
        return queue.size() == capacity;
    }
};