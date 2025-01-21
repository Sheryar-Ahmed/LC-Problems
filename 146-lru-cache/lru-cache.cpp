// [mostRecent] <-> [Node(2, 20)] <-> [Node(1, 10)] <-> [leastRecent]
class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->mostRecent = new Node(0, 0); // Dummy node for most recently used
        this->leastRecent = new Node(0, 0); // Dummy node for least recently used
        mostRecent->next = leastRecent;
        leastRecent->prev = mostRecent;
    }

    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* targetNode = cacheMap[key];
            moveToMostRecent(targetNode); // Move the accessed node to the most recent position
            return targetNode->value;
        }
        return -1; // Key not found
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* existingNode = cacheMap[key];
            removeNode(existingNode);
            cacheMap.erase(key);
        }

        if (cacheMap.size() == capacity) {
            // Remove least recently used node (leastRecent's previous node)
            Node* lruNode = leastRecent->prev;
            removeNode(lruNode);
            cacheMap.erase(lruNode->key);
            delete lruNode;
        }

        // Add the new node as the most recently used
        Node* newNode = new Node(key, value);
        addAsMostRecent(newNode);
        cacheMap[key] = newNode;
    }

private:
    int capacity;
    unordered_map<int, Node*> cacheMap; // Map key to Node pointer
    Node* mostRecent; // Dummy node representing the most recently used
    Node* leastRecent; // Dummy node representing the least recently used

    // Add a node right after the mostRecent node
    void addAsMostRecent(Node* newNode) {
        newNode->next = mostRecent->next;
        newNode->prev = mostRecent;
        mostRecent->next->prev = newNode;
        mostRecent->next = newNode;
    }

    // Remove a node from the linked list
    void removeNode(Node* targetNode) {
        Node* prevNode = targetNode->prev;
        Node* nextNode = targetNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Move a node to the mostRecent position (mark as most recently used)
    void moveToMostRecent(Node* targetNode) {
        removeNode(targetNode);
        addAsMostRecent(targetNode);
    }
};

/**
 * Usage:
 * LRUCache* cache = new LRUCache(capacity);
 * int value = cache->get(key);
 * cache->put(key, value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */