class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";

        const auto& pairs = store[key];
        int L = 0, R = pairs.size() - 1;
        string result = "";

        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (pairs[mid].first <= timestamp) {
                result = pairs[mid].second; // candidate
                L = mid + 1; // search right for newer timestamp
            } else {
                R = mid - 1;
            }
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */