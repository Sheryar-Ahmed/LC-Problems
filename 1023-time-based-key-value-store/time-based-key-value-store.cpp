class TimeMap {
public:
    // Define a map where each key points to a vector of pairs (timestamp, value)
    unordered_map<string, vector<pair<int, string>>> kvds;

    TimeMap() {
        // Constructor
    }
    
    void set(string key, string value, int timestamp) {
        // Push the (timestamp, value) pair into the vector for the key
        kvds[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        // If the key doesn't exist, return an empty string
        if (kvds.find(key) == kvds.end()) {
            return "";
        }

        // Get the vector of pairs for the key
        const auto& records = kvds[key];
        
        // Use binary search to find the appropriate timestamp
        int L = 0, R = records.size() - 1;
        string result = "";

        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (records[mid].first <= timestamp) {
                // If the current timestamp is less than or equal to the target
                result = records[mid].second;
                L = mid + 1; // Search in the right half
            } else {
                R = mid - 1; // Search in the left half
            }
        }
        
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key, value, timestamp);
 * string param_2 = obj->get(key, timestamp);
 */
